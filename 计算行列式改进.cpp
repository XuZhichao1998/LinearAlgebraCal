#include<iostream>
#include<cstdio> 
#include<cmath>
#define N 20
using namespace std;
double det(double aaa[N][N],int n);
int main()
{
    int steps;
    double arr[N][N];
    double D;
        cout<<"This little program is designed by XuZhichao."<<endl;
        cout<<"It can help you calculate the determinant.Enjoy it."<<endl<<endl;
        cout<<"请输入行列式的阶数：";
        while(cin>>steps&&steps!='#')
  {
        cout<<"请按顺序输入它的每一项：\n";
        for(int i=0;i<steps;i++)
            for(int j=0;j<steps;j++)
            cin>>arr[i][j];
        D=det(arr,steps);
        cout<<"结果是：";
        printf("%.10lf\n\n",D);
            cout<<"你可以继续输入行列式的阶数(或输入#结束)：";


  }cout<<"Bye-bye!Wish You a Good Luck!";
return 0;
}
double det(double aaa[N][N],int n)
{
	double a[N][N];
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	     a[i][j]=aaa[i][j];
    double D;
    if(n==1){D=a[0][0];return D;}
    if(n==2){D=a[0][0]*a[1][1]-a[0][1]*a[1][0];return D;}
    if(n>=3)
    {
        D=0.0;
        double line1[N];
        double temp[N][N];
        for(int i=0;i<n;i++)
            {line1[i]=a[i][0]*pow(-1,i+2);}
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                temp[i][j]=a[i][j+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int r=i;r<n-1;r++)
            {
                for(int c=0;c<n;c++)
                {
                    a[r][c]=temp[r+1][c];
                }
            }
            D+=line1[i]*det(a,n-1);
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n;j++)
                    a[i][j]=temp[i][j];
            }
        }
        return D;
    }
}

