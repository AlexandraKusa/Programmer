#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{
    int n, m;
    cout<<"Dimension a = ";
    cin>>n;
    cout<<"Dimension b = ";
    cin>>m;
    float *a=new float[n];
    float *b=new float[m];
    cout<<"Array a"<<endl;
    for(int i=0;i<n;i++) 
	{
        cin>>a[i];
    }
    cout<<"Array b"<<endl;
    for(int j=0;j<m;j++) 
	{
        cin>>b[j];
    }
    int nonMultipleA=0;
    for(int i=0;i<n;i++) 
	{
        if((int)a[i]%3!=0) 
		{
            nonMultipleA++;
        }
    }
    int nonMultipleB=0;
    for(int j=0;j<m;j++) 
	{
        if((int)b[j]%3!=0) 
		{
            nonMultipleB++;
        }
    }
    if(nonMultipleA>nonMultipleB) 
	{
        cout<<"More in a = ";
        for(int i=0;i<n;i++) 
		{
            if((int)a[i]%3!=0) 
			{
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    } 
	else 
	{
        cout<<"More in b = ";
        for(int j=0;j<m;j++) 
		{
            if((int)b[j]%3!=0) 
			{
                cout<<b[j]<<" ";
            }
        }
        cout<<endl;
    }
    delete[] a;
    delete[] b;     

    return 0;
}
