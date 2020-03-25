/*2018.1.10.0��12
*���ǳ�*
��������ʽÿ�л��е�����ʽ���������ʽ֮��*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#define N 20
double a[N][N],b[N][N];
using namespace std;
double det(double aaa[N][N],int n);
int main()
{
	cout<<"Designed by ���ǳ�\n";	cout<<"-----------------------------------------------------\n"; 
	int r,n,result(0);
	cout<<"�������Ĺ����Ǽ�������ʽĳ������ʽ֮�ͣ�\n";
	cout<<"-----------------------------------------------------\n";
	cout<<"��������ʽ������";
	while(cin>>n) {
		cout<<"�밴˳������"<<n<<"������ʽ��"<<n*n<<"����\n"; 
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];b[i][j]=a[i][j];
			}
		cout<<"���������ʽΪ��\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<setw(4)<<a[i][j]<<" ";cout<<endl;
		}
		for(r=0;r<n;r++)
		{
			for(int k=0;k<n;k++) b[r][k]=1;
			result=det(b,n);
			cout<<"��"<<r+1<<"�и�Ԫ�ش�������ʽ֮�͵�ֵΪ��"<<setw(4)<<result<<"\t";
			for(int k=0;k<n;k++) b[r][k]=pow(-1,r+k);
			result=det(b,n);
			cout<<"��"<<r+1<<"�и�Ԫ������ʽ֮�͵�ֵΪ��"<<setw(4)<<result<<endl; 
			
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					b[i][j]=a[i][j];	
		}
		cout<<endl;
		for(int c=0;c<n;c++)
		{
			for(int k=0;k<n;k++) b[k][c]=1;
			result=det(b,n);
			cout<<"��"<<c+1<<"�и�Ԫ�ش�������ʽ֮�͵�ֵΪ��"<<setw(4)<<result<<"\t";
			
			for(int k=0;k<n;k++) b[k][c]=pow(-1,c+k);
			result=det(b,n);
			cout<<"��"<<c+1<<"�и�Ԫ������ʽ֮�͵�ֵΪ��"<<setw(4)<<result<<endl;

			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					b[i][j]=a[i][j];
				
		}
		cout<<"-----------------------------------------------------\n"<<"��������ʽ����(*�˳�)��" ; 		
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
