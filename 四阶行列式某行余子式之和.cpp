/*     2018.1.9许智超
*计算四阶行列式某行余子式之和*
*代数余子式之和为其相反数*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#define N 20
double a[N][N];
using namespace std;
double det(double aaa[N][N],int n);
int main()
{
	cout<<"Designed by 许智超\n"; 
	int r,n(4),result(0);
	cout<<"这个程序的功能是计算四阶行列式某行余子式之和：\n";
	cout<<"-----------------------------------------------------\n";
	cout<<"输入行序号：";
	while(cin>>r) {
		if(r<1||r>n){cout<<"输错了！请重新输入行序号：";continue; }
		cout<<"请输入这个四阶行列式：\n"; 
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		for(int k=0;k<n;k++)
		a[r-1][k]=pow(-1,r-1+k);//因为第 
		result=det(a,n);
		cout<<"相当于求下面构造出的行列式的值：\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<setw(3)<<a[i][j]<<" ";
			cout<<endl;
		 } 
		cout<<"该"<<n<<"阶行列式的第"<<r<<"行的余子式之和为："<<result<<endl;
		cout<<"-----------------------------------------------------\n"<<"输入行序号(*退出)：" ; 
		memset(a,0,sizeof(a));		
	}
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
