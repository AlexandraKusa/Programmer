#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{
    int n;
    cout<<"Dimension a = ";
    cin>>n;
    float a[n];
    cout<<"Array a"<<endl;
    for(int i=0;i<n;i++) 
	{
        cin>>a[i];
    }
    int m=n/2; 
    float *b=new float[m];
    int j=0; 

    for(int i=1;i<n;i+=2) 
	{
        if((int)a[i]%2==0) 
		{ 
            b[j++]=a[i];
        }
    }
    cout<<"Even elements in odd places = ";
    for(int i=0;i<j;i++) 
	{
        cout<<b[i]<<" ";
    }
    cout<<endl;
    delete[] b;

    return 0;
}

