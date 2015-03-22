#include <iostream>
#include "matrix.h"


using namespace std;

int main()
{
    int cols = 0;
    int rows = 0;
    double value;

    cout << "Enter cols amount: "; cin >> cols;
    cout << endl;
    cout << "Enter rows amount: "; cin >> rows;
    cout << endl;
    Matrix myMatrix1(cols, rows);

    cout << "Initialize matrix..." << endl;

    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows; j++)
        {
            cin >> value;
            myMatrix1.Set(i, j, value);
        }

   myMatrix1.ShowMatrix();
   myMatrix1.GetCol(5);
   myMatrix1.GetRow(5);
    return 0;
}



