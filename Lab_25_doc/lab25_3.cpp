#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void findMinIndices(int *A, int n, int m, int *minIndices) 
{
    for (int i = 0; i < n; i++) 
	{
        int minIndex = 0;
        for (int j = 1; j < m; j++) 
		{
            if (*(A + i * m + j) < *(A + i * m + minIndex)) 
			{
                minIndex = j;
            }
        }
        minIndices[i] = minIndex;
    }
}

int main() 
{
    int n, m;
    cout << "Dimension = ";
    cin >> n >> m;

    int A[n][m];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < m; j++) 
		{
            cin >> A[i][j];
        }
    }

    int minIndices[n];
    findMinIndices(&A[0][0], n, m, minIndices);

    cout << "Indices of the minimum elements in each row:" << endl;
    for (int i = 0; i < n; i++) 
	{
        cout << minIndices[i] << " ";
    }
    cout << endl;

    return 0;
}

