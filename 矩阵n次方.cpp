#include<iostream>
using namespace std;
const int N=35;
int main()
{
	int a[N][N]={0},b[N][N]={0},c[N][N]={0};
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<n;j++)
		{cin>>a[i][j];
		 c[i][j]=a[i][j];
		}
	}
	for(int L=0;L<m-1;L++)
	{	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				b[i][j]=c[i][j];
				c[i][j]=0;
			}
		}
		
	
	   for(int i=0;i<n;i++)
	   {
		   for(int j=0;j<n;j++)
		   {
		       for(int k=0;k<n;k++)
			   {
				   c[i][j]+=a[i][k]*b[k][j];
			   }
		   }
	   }
    }
    
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
