#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix
{
public:
    Matrix();
    Matrix(int colsN, int rowsN);
    Matrix ( const Matrix & Original);
    ~Matrix();

    void Set(int colsN, int rowsN, double value);
    double Get(int colsN, int rowsN);
    int Columns();
    int Rows ();
    double * GetRow(int rowNumber);
    double * GetCol(int colNumber);
    void ShowMatrix (); //TODO: Реализовать!

    Matrix operator+(const Matrix & rhs);
    Matrix operator-(const Matrix & rhs);
    Matrix operator*(const Matrix & rhs); //TODO: думать про приоритет!!!
    Matrix operator*(double number);
    Matrix Transpose();
    //void Diagonalize(); //TODO: Определить // Заебусь!
    Matrix Inverse( double eps/*Задать точность, значение по умолчанию*/); //TODO: Определить
    void Rotation(/*Axis, int degree*/); // TODO: Определить перечисляемый тип, функцию, задать пределы градусов
    double Determinant();

private:
    Matrix Minor(int number);
    inline double CompareDouble (double value, double precision) const;
    inline bool IsEqualSize(int cols1, int cols2, int rows1, int rows2) const;
    inline bool IsSquare (int colsN, int rowsN) const;
    inline int InRange (int numberInRange, int borderValue) const;

    int cols; // Столбцы
    int rows; // Строки
    double * buffer;
};

#endif // _MATRIX_H
