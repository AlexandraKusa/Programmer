#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main() 
{
int n, i, j;
cout << "Dimension = ";
cin >> n;
int a[n][n];
int *gol; 
int *bi;  
int max;
int min;

  for (i = 0; i < n; ++i) 
{
  for (j = 0; j < n; ++j) 
{
  cin>>a[i][j];
   if (i == j && a[i][j] > max) 
{
   max = a[i][j];
   gol = &a[i][j]; 
}
    if (i + j == n - 1 && a[i][j] < min) 
{
    min = a[i][j];
    bi = &a[i][j]; 
}
}
}

cout << "Max: " << *gol << endl;
cout << "Min: " << *bi << endl;

int t = *gol - *bi;
cout << "Difference = " << t << endl;

return 0;
}

