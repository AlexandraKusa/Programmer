#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void printMatrix(int *A, int n, int m) 
{
    for (int i = 0; i < n; ++i) 
	{
        if (i % 2 == 0) 
		{  
            for (int j = 0; j < m; ++j) 
			{
                cout << *(A + i * m + j) << " ";
            }
        } 
		else 
		{  
            for (int j = m - 1; j >= 0; --j) 
			{
                cout << *(A + i * m + j) << " ";
            }
        }
        cout << endl;
    }
}

int main() 
{
    int n, m;
    cout << "Dimension = ";
    cin >> n >> m;

    int A[n][m];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Matrix in the specified order:" << endl;
    printMatrix(&A[0][0], n, m);

    return 0;
}

