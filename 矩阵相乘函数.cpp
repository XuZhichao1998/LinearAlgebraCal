#include<iostream>
using namespace std;
const int N=20;
//函数求矩阵mat1和mat2相乘,用product记录结果 
void matrix(double mat1[N][N],double mat2[N][N],double product[N][N],int m,int n,int p,int q)
{
	for(int i=0;i<m;i++)
    {
       for(int j=0;j<q;j++)
       {
           for(int k=0;k<n;k++)
           {
               product[i][j]+=mat1[i][k]*mat2[k][j];
           }
       }
    }
}
int main()
{
   int m,n,p,q;
   double a[N][N]={0},b[N][N]={0},c[N][N]={0};
   cin>>m>>n>>p>>q;
   for(int i=0;i<m;i++)//输入矩阵a[][]
      for(int j=0;j<n;j++)
	     cin>>a[i][j];	
   for(int i=0;i<p;i++)//输入矩阵b[][] 
      for(int j=0;j<q;j++)
	     cin>>b[i][j];
   matrix(a,b,c,m,n,p,q);//调用函数 
   for(int i=0;i<m;i++)//输出结果 
   {
   	for(int j=0;j<q;j++)
   	{
   		cout<<c[i][j]<<"  ";
	}cout<<endl;
   }
return 0;
}
