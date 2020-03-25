/*     2018.1.9���ǳ�
*�����Ľ�����ʽĳ������ʽ֮��*
*��������ʽ֮��Ϊ���෴��*/
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
	cout<<"Designed by ���ǳ�\n"; 
	int r,n(4),result(0);
	cout<<"�������Ĺ����Ǽ����Ľ�����ʽĳ������ʽ֮�ͣ�\n";
	cout<<"-----------------------------------------------------\n";
	cout<<"��������ţ�";
	while(cin>>r) {
		if(r<1||r>n){cout<<"����ˣ���������������ţ�";continue; }
		cout<<"����������Ľ�����ʽ��\n"; 
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		for(int k=0;k<n;k++)
		a[r-1][k]=pow(-1,r-1+k);//��Ϊ�� 
		result=det(a,n);
		cout<<"�൱�������湹���������ʽ��ֵ��\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<setw(3)<<a[i][j]<<" ";
			cout<<endl;
		 } 
		cout<<"��"<<n<<"������ʽ�ĵ�"<<r<<"�е�����ʽ֮��Ϊ��"<<result<<endl;
		cout<<"-----------------------------------------------------\n"<<"���������(*�˳�)��" ; 
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
