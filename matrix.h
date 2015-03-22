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
    void ShowMatrix (); //TODO: �����������!

    Matrix operator+(const Matrix & rhs);
    Matrix operator-(const Matrix & rhs);
    Matrix operator*(const Matrix & rhs); //TODO: ������ ��� ���������!!!
    Matrix operator*(double number);
    Matrix Transpose();
    //void Diagonalize(); //TODO: ���������� // �������!
    Matrix Inverse( double eps/*������ ��������, �������� �� ���������*/); //TODO: ����������
    void Rotation(/*Axis, int degree*/); // TODO: ���������� ������������� ���, �������, ������ ������� ��������
    double Determinant();

private:
    Matrix Minor(int number);
    inline double CompareDouble (double value, double precision) const;
    inline bool IsEqualSize(int cols1, int cols2, int rows1, int rows2) const;
    inline bool IsSquare (int colsN, int rowsN) const;
    inline int InRange (int numberInRange, int borderValue) const;

    int cols; // �������
    int rows; // ������
    double * buffer;
};

#endif // _MATRIX_H
