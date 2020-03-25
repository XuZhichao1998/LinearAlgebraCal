#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#define N 20
double a[N][N],temp[N][N];
int number[30];
using namespace std;
double det(double aaa[N][N],int n);  //行列式的值 
void ALG_complement_one(double arr[N][N],int n,int r,int c);
double alg_complement_one(double arr[N][N],int n,int r,int c);
int main(void)
{
	int n=4,i,j,k,l,divisor,flagg;
	int character_value[50]={0};
	double s[N]={0};
	printf("Designed by 许智超\n化简n阶行列式的特征多项式。\n输入任意数字开始：");
	while(scanf("%d",&flagg)!=EOF)
	{
	    printf("------------------------------------------------------------\n输入四阶方阵：\n");
		memset(s,0,sizeof(s));  //s[i]储存i次项的系数
		memset(a,0,sizeof(a));  //a[N][N]储存输入的方阵
		memset(number,0,sizeof(number));//
		memset(character_value,0,sizeof(character_value));// 储存特征值
		for(i=0;i<n;i++)
			for(int j=0;j<n;j++)
			cin>>a[i][j];
		cout<<"输入的行列式为：\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			cout<<setw(4)<<a[i][j];
			cout<<endl;
		}
		s[n]=pow(-1,n);
		cout<<"-------------------------------------------------------\n";
		cout<<"最高次项系数即第"<<n<<"次项系数为(-1)^n即"<<"(-1)^"<<n<<" = "<<s[n]<<endl<<"-------------------------------------------------------\n";
		s[0]=det(a,n);
		cout<<"常数项为原方阵的行列式："<<s[0]<<endl<<"-------------------------------------------------------\n";


		for(i=0;i<n;i++)
		s[n-1]+=a[i][i];s[n-1]*=pow(-1,n-1);
		cout<<"次高次项即"<<n-1<<"次项系数为：(-1)^"<<n-1<<" * tr(A)=";
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
		    cout<<endl<<"*****************************\n"<<"对"<<i<<"次项系数进行研究：\n";
		    cout<<i<<"次项系数即含有"<<i<<"个X相乘，设第K行的X为Xk,则"<<i<<"次项只有n个X中的"<<i<<"个。\n"; 
			for(j=0;j<n-1;j++)
			{
				for(k=j+1;k<n;k++)
				{
					for(l=0;l<n;l++)
					for(int ll=0;ll<n;ll++)
					temp[l][ll]=a[l][ll];
					ALG_complement_one(temp,n,j,j);
					ALG_complement_one(temp,n-1,k-1,k-1);
					cout<<"选取a"<<j+1<<j+1<<"和a"<<k+1<<k+1<<"，划掉这"<<i<<"个元素所在行、列的元素后，得到的"<<n-i<<"阶方阵如下:\n";
					for(int iii=0;iii<n;iii++)
					{
						for(int jjj=0;jjj<n;jjj++)
						cout<<temp[iii][jjj]<<" ";
						cout<<endl;
					}
					s[i]+=det(temp,n-i);cout<<"这个新的"<<n-i<<"阶方阵的行列式 = "<<det(temp,n-i)<<endl;
					memset(temp,0,sizeof(temp));
					cout<<"---------------------------\n";
					 

				}
			}
			s[i]*=pow(-1,i);
			cout<<"把这些小方阵的行列式加起来再乘以"<<i<<"的-1次得特征方程的"<<i<<"次项的系数为"<<s[i]<<endl;
		}
		cout<<endl;
		cout<<"该"<<n<<"阶方阵的特征方程为:\n"; 
		cout<<"("<<s[n]<<")"<<"X^"<<n;
		for(i=n-1;i>=0;i--)
		cout<<"+("<<s[i]<<")"<<"X^"<<i<<" ";cout<<endl;











		//试根
		/*
		double flag;
		int tap=0;
		int s=(int)s0;
		if(s<0)s*=-1;
		for(i=1;i<=s;i++)
		{
			if(s%i==0){
                flag=i*i*i*s3+i*i*s2+i*s1+s0;
                if(!flag){character_value[tap]=i;cout<<"第"<<++tap<<"个特征值为："<<setw(3)<<i<<endl;if(tap==n)break;}
                int ii=i*-1;
                flag=ii*ii*ii*s3+ii*ii*s2+ii*s1+s0;
                if(!flag){character_value[tap]=ii;cout<<"第"<<++tap<<"个特征值为："<<setw(3)<<ii<<endl;if(tap==n)break;}
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
            cout<<"第"<<i+1<<"个特征值"<<setw(3)<<character_value[i]<<"对应的行列式为：\n";
            for(int p=0;p<n;p++)
            {
                for(int q=0;q<n;q++)
                    cout<<setw(4)<<temp[p][q]<<" ";
                cout<<endl;
            }

        }
        */
		cout<<"------------------------------------------------------------\n";
		cout<<"输入任意数字继续算(*退出)：";
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
    for(int k=r;k<n-1;k++)      //把a[r][c]所在行都用下边一行元素替换掉，相当于把a[r][c]所在行的元素划去
    {
        for(int l=0;l<n;l++)
        {
            temp[k][l]=temp[k+1][l];
        }
    }
    for(int k=0;k<n-1;k++)     //把a[r][c]所在列都用右边一列元素替换掉，相当于把a[r][c]所在列的元素划去
    {
        for(int l=c;l<n-1;l++)
        {
            temp[k][l]=temp[k][l+1];
        }
    }                         //此时temp[n-1][n-1]为a[i][j]元素的余子式
    A=det(temp,n-1)*pow(-1,c+r+2); //A为所求的相应元素的代数余子式行列式的值
	return A;
}

void ALG_complement_one(double arr[N][N],int n,int r,int c)//此函数功能是把行列式变为某元素的余子式（划去所在行、列）
{
    for(int k=r;k<n;k++)      //把arr[r][c]所在行都用下边一行元素替换掉，相当于把a[r][c]所在行的元素划去
    {
        for(int l=0;l<n;l++)
        {
            arr[k][l]=arr[k+1][l];
        }
    }
    for(int k=0;k<n;k++)     //把arr[r][c]所在列都用右边一列元素替换掉，相当于把a[r][c]所在列的元素划去
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
