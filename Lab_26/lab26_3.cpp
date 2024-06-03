#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{
    int n;
    cout<<"Dimension a = ";
    cin>>n;
    float *a=new float[n]; 
    cout<<"Array a = ";
    for(int i=0;i<n;i++) 
	{
        cin>>a[i];
    }
    int m=0;
    for(int i=0;i<n;i++) 
	{
        if((int)a[i]%2==0) 
		{ 
		++m;
        }
    }
    float *b=new float[m];
    int j=0;
    for(int i=0;i<n;i++) 
	{
        if((int)a[i]%2==0) 
		{ 
            int k=j-1;
            while(k>=0&&b[k]>a[i]) 
			{ 
                b[k+1]=b[k];
                --k;
            }
            b[k+1]=a[i];
            ++j;
        }
    }
    cout<<"Array b = ";
    for(int i=0;i<m;i++) 
	{
        cout<<b[i]<<" ";
    }
    cout<<endl;
    
    delete[] a;
    delete[] b;

    return 0;
}
