#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#define N 20
double a[N][N],temp[N][N];
int number[30];
using namespace std;
double det(double aaa[N][N],int n);  //����ʽ��ֵ 
void ALG_complement_one(double arr[N][N],int n,int r,int c);
double alg_complement_one(double arr[N][N],int n,int r,int c);
int main(void)
{
	int n=4,i,j,k,l,divisor,flagg;
	int character_value[50]={0};
	double s[N]={0};
	printf("Designed by ���ǳ�\n����n������ʽ����������ʽ��\n�����������ֿ�ʼ��");
	while(scanf("%d",&flagg)!=EOF)
	{
	    printf("------------------------------------------------------------\n�����Ľ׷���\n");
		memset(s,0,sizeof(s));  //s[i]����i�����ϵ��
		memset(a,0,sizeof(a));  //a[N][N]��������ķ���
		memset(number,0,sizeof(number));//
		memset(character_value,0,sizeof(character_value));// ��������ֵ
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
		s[n]=pow(-1,n);
		cout<<"-------------------------------------------------------\n";
		cout<<"��ߴ���ϵ������"<<n<<"����ϵ��Ϊ(-1)^n��"<<"(-1)^"<<n<<" = "<<s[n]<<endl<<"-------------------------------------------------------\n";
		s[0]=det(a,n);
		cout<<"������Ϊԭ���������ʽ��"<<s[0]<<endl<<"-------------------------------------------------------\n";


		for(i=0;i<n;i++)
		s[n-1]+=a[i][i];s[n-1]*=pow(-1,n-1);
		cout<<"�θߴ��"<<n-1<<"����ϵ��Ϊ��(-1)^"<<n-1<<" * tr(A)=";
		cout<<"[("<<a[0][0]<<")";
		for(i=1;i<n;i++)
            cout<<"+("<<a[i][i]<<")";
        cout<<"] * ("<<pow(-1,n-1)<<") = "<<s[n-1]<<endl;

		for(i=0;i<n;i++)
		{
			s[1]-=alg_complement_one(a,n,i,i);
		}
		for(i=2;i<n-1;i++)
		{
		    cout<<endl<<"*****************************\n"<<"��"<<i<<"����ϵ�������о���\n";
		    cout<<i<<"����ϵ��������"<<i<<"��X��ˣ����K�е�XΪXk,��"<<i<<"����ֻ��n��X�е�"<<i<<"����\n"; 
			for(j=0;j<n-1;j++)
			{
				for(k=j+1;k<n;k++)
				{
					for(l=0;l<n;l++)
					for(int ll=0;ll<n;ll++)
					temp[l][ll]=a[l][ll];
					ALG_complement_one(temp,n,j,j);
					ALG_complement_one(temp,n-1,k-1,k-1);
					cout<<"ѡȡa"<<j+1<<j+1<<"��a"<<k+1<<k+1<<"��������"<<i<<"��Ԫ�������С��е�Ԫ�غ󣬵õ���"<<n-i<<"�׷�������:\n";
					for(int iii=0;iii<n;iii++)
					{
						for(int jjj=0;jjj<n;jjj++)
						cout<<temp[iii][jjj]<<" ";
						cout<<endl;
					}
					s[i]+=det(temp,n-i);cout<<"����µ�"<<n-i<<"�׷��������ʽ = "<<det(temp,n-i)<<endl;
					memset(temp,0,sizeof(temp));
					cout<<"---------------------------\n";
					 

				}
			}
			s[i]*=pow(-1,i);
			cout<<"����ЩС���������ʽ�������ٳ���"<<i<<"��-1�ε��������̵�"<<i<<"�����ϵ��Ϊ"<<s[i]<<endl;
		}
		cout<<endl;
		cout<<"��"<<n<<"�׷������������Ϊ:\n"; 
		cout<<"("<<s[n]<<")"<<"X^"<<n;
		for(i=n-1;i>=0;i--)
		cout<<"+("<<s[i]<<")"<<"X^"<<i<<" ";cout<<endl;











		//�Ը�
		/*
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
        */
		cout<<"------------------------------------------------------------\n";
		cout<<"�����������ּ�����(*�˳�)��";
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

void ALG_complement_one(double arr[N][N],int n,int r,int c)//�˺��������ǰ�����ʽ��ΪĳԪ�ص�����ʽ����ȥ�����С��У�
{
    for(int k=r;k<n;k++)      //��arr[r][c]�����ж����±�һ��Ԫ���滻�����൱�ڰ�a[r][c]�����е�Ԫ�ػ�ȥ
    {
        for(int l=0;l<n;l++)
        {
            arr[k][l]=arr[k+1][l];
        }
    }
    for(int k=0;k<n;k++)     //��arr[r][c]�����ж����ұ�һ��Ԫ���滻�����൱�ڰ�a[r][c]�����е�Ԫ�ػ�ȥ
    {
        for(int l=c;l<n;l++)
        {
            arr[k][l]=arr[k][l+1];
        }
    }
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
