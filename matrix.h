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

    const Matrix & operator+(Matrix & rhs); //TODO: ����������
    const Matrix & operator-(Matrix & rhs); //TODO: ����������
    const Matrix & operator*(Matrix & rhs); //TODO: ����������
    Matrix & Transpose(); //TODO: ����������
    Matrix Inverse(); //TODO: ����������
    Matrix Diagonalize(); //TODO: ����������
    double Determinant();
private:
    Matrix Minor(int number);
    inline bool IsEqualSize(int cols1, int cols2, int rows1, int rows2) const ; //TODO: ����������
    inline bool IsSquare (int colsN, int rowsN) const; //TODO: ����������
    int cols; // �������
    int rows; // ������
    double * buffer;
};

#endif // _MATRIX_H
