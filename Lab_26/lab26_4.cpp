#include <iostream>
#include <cstdlib> 

using namespace std;

int main() 
{
    int n;
    cout<<"Dimension a = ";
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++) 
	{
        int random=rand()%6-3;
        a[i]=random;
        if(random<0) 
		{
            int min=a[0];
            for(int j=1;j<=i;j++) 
			{ 
                if(a[j]<min) 
				{
                    min=a[j];
                }
            }
            int max=a[0];
            for(int j=1;j<=i;j++) 
			{ 
                if(a[j]>max) 
				{
                    max=a[j];
                }
            }
            a[i]=min+max;
        }
    }
    cout<<"Array a = ";
    for(int i=0;i<n;i++) 
	{
        cout<<a[i]<<" ";
    }
   cout<<endl;
   delete[] a;

   return 0;
}
