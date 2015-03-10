#include <iostream>
#include "matrix.h"


using namespace std;

int main()
{
    int N, value;
    cout << "Enter matrix dimension: ";
    cin >> N;

    Matrix myMatrix(N,N);
    cout << "Matrix initialization..." << endl;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> value;
            myMatrix.Set(i,j, value);
        }
    }

    cout << "Resulting Matrix..." << endl;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << myMatrix.Get(i,j) << "\t";
        }
        cout << endl;
    }
cout << "Determinant is " << myMatrix.Determinant();
    return 0;
}
