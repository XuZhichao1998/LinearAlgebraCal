#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#define N 20
double a[N][N],temp[N][N];
int number[30];
using namespace std;
double det(double aaa[N][N],int n);
double alg_complement_one(double arr[N][N],int n,int r,int c);
int main(void)
{
	int n=3,i,j,k,l,divisor;
	int character_value[50]={0};
	double s1,s2,s3,s0;
	printf("Designed by ���ǳ�\n������������ʽ����������ʽ��\n");
	printf("------------------------------------------------------------\n������������ʽ��\n");
	while(1)
	{
		s1=s2=s0=0;
		s3=pow(-1,n);
		memset(a,0,sizeof(a));
		memset(number,0,sizeof(number));
		memset(character_value,0,sizeof(character_value));
		for(i=0;i<n;i++)
			for(int j=0;j<n;j++)
			cin>>a[i][j];
		cout<<"���������ʽΪ��\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			cout<<setw(4)<<a[i][j];
			cout<<endl;
		}
		s3=pow(-1,n);
		s0=det(a,n);
		for(i=0;i<n;i++)
		s2+=a[i][i];
		for(i=0;i<n;i++)
		{
			s1-=alg_complement_one(a,n,i,i);
		}
		//cout<<s3<<" "<<s2<<" "<<s1<<" "<<s0<<endl;
		cout<<"����������ʽ����������Ϊ��\n("<<s3<<")X^3+("<<s2<<")X^2+("<<s1<<")X+("<<s0<<")\n";
		if(s3<0)cout<<"-";
		if(s3!=1&&s3!=-1)cout<<fabs(s3);   cout<<"X^3";
		if(s2<0)cout<<" - ";else cout<<" + ";
		if(s2!=1&&s2!=-1)cout<<fabs(s2);   cout<<"X^2";
		if(s1<0)cout<<" - ";else cout<<" + ";
		if(s1!=1&&s1!=-1)cout<<fabs(s1);   cout<<"X";
		if(s0<0)cout<<" - ";else cout<<" + ";
		cout<<fabs(s0)<<endl;
		double flag;
		int tap=0;
		int s=(int)s0;
		if(s<0)s*=-1;  
		for(i=1;i<=s;i++)
		{
			if(s%i==0){
                flag=i*i*i*s3+i*i*s2+i*s1+s0;
                if(!flag){character_value[tap]=i;cout<<"��"<<++tap<<"������ֵΪ��"<<setw(3)<<i<<endl;if(tap==n)break;}
                int ii=i*-1;
                flag=ii*ii*ii*s3+ii*ii*s2+ii*s1+s0;
                if(!flag){character_value[tap]=ii;cout<<"��"<<++tap<<"������ֵΪ��"<<setw(3)<<ii<<endl;if(tap==n)break;}
			}
		}
        cout<<"**************************\n";
		for(i=0;i<n;i++)
            cout<<character_value[i]<<"\t";cout<<endl;
        cout<<"**************************\n";
		for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                temp[j][k]=a[j][k];
            for(l=0;l<n;l++)
            {
                temp[l][l]-=character_value[i];
            }
            cout<<"��"<<i+1<<"������ֵ"<<setw(3)<<character_value[i]<<"��Ӧ������ʽΪ��\n";
            for(int p=0;p<n;p++)
            {
                for(int q=0;q<n;q++)
                    cout<<setw(4)<<temp[p][q]<<" ";
                cout<<endl;
            }

        }
		cout<<"------------------------------------------------------------\n";
		cout<<"������������ʽ(*�˳�)��\n";
	}
	return 0;
}

double alg_complement_one(double arr[N][N],int n,int r,int c)
{
    double temp[N][N]={0},A=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            temp[i][j]=arr[i][j];
    }
    for(int k=r;k<n-1;k++)      //��a[r][c]�����ж����±�һ��Ԫ���滻�����൱�ڰ�a[r][c]�����е�Ԫ�ػ�ȥ
    {
        for(int l=0;l<n;l++)
        {
            temp[k][l]=temp[k+1][l];
        }
    }
    for(int k=0;k<n-1;k++)     //��a[r][c]�����ж����ұ�һ��Ԫ���滻�����൱�ڰ�a[r][c]�����е�Ԫ�ػ�ȥ
    {
        for(int l=c;l<n-1;l++)
        {
            temp[k][l]=temp[k][l+1];
        }
    }                         //��ʱtemp[n-1][n-1]Ϊa[i][j]Ԫ�ص�����ʽ
    A=det(temp,n-1)*pow(-1,c+r+2); //AΪ�������ӦԪ�صĴ�������ʽ����ʽ��ֵ
	return A;
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
