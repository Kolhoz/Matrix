#include<iostream>
#include "matrix.h"
#include <cmath>

using namespace std;
int counter = 0;
/************************************Конструкторы и деструктор*****************************/
Matrix::Matrix()
{
    buffer = nullptr;
    cols=0;
    rows=0;
    cout << "Default Constructor..." << endl;
}

Matrix::Matrix(int colsN, int rowsN)
{
    buffer = new double [colsN*rowsN];
    cols = colsN;
    rows = rowsN;
    cout << "User Constructor..." << endl;
}

Matrix::Matrix( const Matrix & Original)
{
    cols = Original.cols;
    rows = Original.rows;
    buffer = new double [cols*rows];
    for (int i = 0; i < cols*rows; ++i)
        buffer[i] = Original.buffer[i];
    cout << "Copy constructor..." << endl;
}

Matrix::~Matrix()
{
    cout << "Destructor" << endl;
    delete [] buffer;
}

/***************************************Методы доступа*************************************/
void Matrix::Set(int rowNumber, int colNumber, double value)
{   buffer[rowNumber*rows+colNumber] = value;   }

double Matrix::Get(int rowNumber, int colNumber)
{
    if ((colNumber > cols)||(rowNumber>rows))
            return 0;
    else    return buffer[rowNumber*cols+colNumber];
}

int Matrix::Columns()
{ return cols; }

int Matrix::Rows ()
{ return rows; }

double * Matrix::GetRow(int rowN)
{
    int rowNumber = InRange(rowN, rows);
    double row[cols];
    for (int i = 0; i < cols; i++)
    {
        row[i]= buffer[cols*rowNumber + i];
        cout << row[i] << "\t";
    }
    cout << endl;
    return row;
}

double * Matrix::GetCol(int colN)
{
    int colNumber = InRange(colN, cols);
    double column [rows];
    for (int i = 0; i < rows; i++)
    {
        column[i] = buffer[i*cols + colNumber];
        cout << column[i] << endl;
    }
    cout << endl;
    return column;
}

void Matrix::ShowMatrix()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
            cout << (this->Get(i, j)) << "\t";
        cout << endl;
    }
}

/***************************************Методы проверки************************************/
bool Matrix::IsEqualSize (int cols1, int cols2, int rows1, int rows2) const
{
    if ((cols1==cols2) && (rows1 == rows2))
            return true;
    else    return false;
}

bool Matrix::IsSquare (int colsN, int rowsN) const
{
    if (colsN == rowsN)
            return true;
    else    return false;
}

double Matrix::CompareDouble (double value, double precision) const
{
    if(value < precision)   return 0;
    else                    return value;
}

int Matrix::InRange (int number, int border) const
{
    if ((number < border) && (number >=0))
            return number;
    else    return (border - 1);
}
/****************************************Операции******************************************/
double Matrix::Determinant()
{
    if ( (cols < 2) &&(rows < 2) )
    {
        cout << "Invalid matrix dimension!" << endl;
        return 0;
    }
    double det = 0;
    double plus_minus = 0;
    if (cols == 2)
      det = this->Get(0,0) * this->Get(1,1) - this->Get(0,1)* this->Get(1,0);
    else
    {
 // Считаем миноры по верхней строчке
        for (int i = 0; i < cols; ++i)
        {
            if (i%2 == 0)
                    plus_minus = 1;
            else    plus_minus = -1;
            det += plus_minus * (this->Get(0, i)) * Minor(i).Determinant();
        }
    }
    return det;
}

Matrix Matrix::Minor(int number)
{
    int itsCols = cols -1;
    int itsRows = rows -1;
    Matrix Temp(itsCols, itsRows);

    double value = 0;
    int k = 0;
    for(int i = 0; i< itsCols; ++i)
    {
        for (int j = 0; j < itsRows; ++j)
        {
            if (j < number) k = j;
            else            k = j+1;
                    value = this->Get(i+1, k);
                    Temp.Set(i,j,value);
        }
    }
    return Temp;
}

Matrix Matrix::Transpose()
{
    Matrix Temp (cols, rows);
    double value = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            value = this->Get(i, j);
            Temp.Set(j, i, value);
        }
    return Temp;
}

Matrix Matrix::Inverse( double eps )
{
    Matrix Unit (cols, rows);
    if (!IsSquare(cols, rows))
    {
        cout << "Matrix is not square, Operation aborted!" << endl;
        return *this;
    }
    else
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                    Unit.Set(i, j, 1);
                else Unit.Set(i, j, 0);
            }

        double /*value, valueU,*/ diffM, diffU;
        for (int k = 0; k < rows; k++)
        {
  //          value = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
    //                value = Get(k, k);
     //               valueU = Get(k, k);

     //               if (value !=0)
     //                   value = Get(k, j) / value; //TODO: Рассмотреть случаи, когда 0!!!
      //              if (value !=0)
     //                   valueU = Unit.Get(k, j)/ valueU; //TODO: Рассмотреть случаи, когда 0!!!


      //              Set(k, j, value);
       //             Unit.Set(k, j, valueU);

                    diffM = diffU = 0;
                    if (i != k)
                    {
                        diffM = CompareDouble(Get(i, j) - Get(i,k)*Get(k,j)/Get(k,k), eps);
                        Set(i, j, diffM);

                        diffU = CompareDouble(Unit.Get(i, j) - Get(i, k)*Unit.Get(k,j)/Get(k, k), eps);
                        Unit.Set(i, j, diffU);
                    }
                    else continue;
                }
            }
        }
    }
    return Unit;
}

/***************************************Переопределение операторов*************************/
Matrix Matrix::operator+(const Matrix & rhs)
{
    if (!IsEqualSize(cols, rhs.cols, rows, rhs.rows))
        {
        cout << "Matrices have different sizes!!! Operation + aborted!!!" << endl;
        return *this;
        }
    else
    {
        Matrix Temp(cols, rows);
        for (int i =0; i< (cols*rows); i++)
        Temp.buffer[i]=buffer[i]+rhs.buffer[i];
        return Temp;
    }
}

Matrix Matrix::operator*(double number)
{
    Matrix Temp(this->cols, this->rows);
    for (int i = 0; i < cols*rows; ++i)
        Temp.buffer[i] = buffer[i] * number;
    return Temp;
}

Matrix Matrix::operator*(const Matrix & rhs)
{
    if (!IsSquare(this->cols, rhs.rows) ) // Должны совпадать число строк левой с числом столбцов правой матрицы
    {
        cout << "Matrices have different sizes!!! Operation + aborted!!!" << endl;
        return *this;
    }
    else
    {
        Matrix Temp (this->rows, rhs.cols);
        Matrix A = rhs;
        double value;
        for(int k = 0; k < this->rows; k++)
        {
            for (int i = 0; i< rhs.cols; i++)
            {
                value = 0;
                for (int j = 0; j < rhs.rows; j++)
                    value += (this->Get(k, j)) *   (A.Get(j,i));
                Temp.Set(k, i, value);
            }
        }
        return Temp;
    }
}

Matrix Matrix::operator-(const Matrix & rhs)
{
    Matrix Sub = rhs;
    Matrix Temp = Sub*(-1) + *this;
    return Temp;
}



