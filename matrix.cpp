#include<iostream>
#include "matrix.h"
#include <cmath>

using namespace std;
int counter = 0;
/*****************************
/ Стандартный конструктор
*****************************/
Matrix::Matrix()
{
    buffer = nullptr;
    cols=0;
    rows=0;
}

/*****************************
/ Пользовательский конструктор
******************************/
Matrix::Matrix(int colsN, int rowsN)
{
    buffer = new double [colsN*rowsN];
    cols = colsN;
    rows = rowsN;
}

/*****************************
/ Конструктор копирования
******************************/
Matrix::Matrix( const Matrix & Original)
{
    cols = Original.cols;
    rows = Original.rows;
    buffer = new double [cols*rows];
    for (int i = 0; i < cols*rows; ++i)
        buffer[i] = Original.buffer[i];
}


/*****************************
/ Деструктор
*****************************/
Matrix::~Matrix()
{
    delete [] buffer;
}

/*****************************
//Установить значение элемента value, находящегося в столбце colNumber и строке rowNumber
*****************************/
void Matrix::Set(int colNumber, int rowNumber, double value)
{
   buffer[rowNumber*cols+colNumber] = value;
}

/*****************************
//Получить значение элемента, находящегося в столбце colNumber и строке rowNumber
*****************************/
double Matrix::Get(int colNumber, int rowNumber)
{
    return buffer[rowNumber*cols+colNumber];
}

/*****************************
//Вычислить определитель квадратной матрицы
*****************************/
double Matrix::Determinant()
{
cout << "Call determinant #" << ++counter << endl;
    if ( (cols < 2) &&(rows < 2) )
    {
        cout << "Invalid matrix dimension!" << endl;
        return 0;
    }

    double det = 0;
    double plus_minus = 0;
    if (cols == 2)
      det = buffer[0] * buffer[3] - buffer[1]* buffer[2];
    else
    {
 // Считаем миноры по верхней строчке
        for (int i = 0; i < cols; ++i)
        {
            if (i%2 == 0)
                    plus_minus = 1;
            else    plus_minus = -1;
            det += plus_minus*buffer[i*cols]*Minor(i).Determinant();
cout << "buffer: " << buffer[i*cols] << endl;
cout << "Current determinant: " << det << endl;
        }
    }
cout << "Resulting determinant: " << det << endl;
    return det;
}
/*****************************
//Вычислить минор матрицы
//Это вспомогательная функция для вычисления определителя, закрытая
*****************************/
Matrix Matrix::Minor(int number)
{
cout << "Call minor #" << number << endl;
    int itsCols = cols -1;
    int itsRows = rows -1;
    Matrix Temp(itsCols, itsRows);

    double dobleBuf[cols][rows];

    for (int i = 0; i<cols; ++i)
        for (int j = 0; j < rows; ++j)
            dobleBuf[i][j] = buffer[j*cols+i];

cout << "Show initial matrix..." << endl;
   for (int i=0; i< cols; i++)
   {
       for (int j = 0; j< rows; j++)
        cout << dobleBuf[i][j] << "\t";
       cout << endl;
   }
int k = 0;
cout << "Minoring..." << endl;
    for(int i = 0; i< itsCols; ++i)
    {
        for (int j = 0; j < itsRows; ++j)
        {
            if (j < number) k = j;
            else            k = j+1;
                    Temp.buffer[i*itsCols + j] = dobleBuf[i+1][k];
                    cout << Temp.buffer[i*itsCols + j] << "\t";
        }
        cout << endl;
    }

    return Temp;
}



const Matrix & operator+(Matrix & rhs)
{

    //TODO: проверка матриц на размеры
    for (int i =0; i< cols*rows; i++)
    {
        buffer[i]=
    }
}
