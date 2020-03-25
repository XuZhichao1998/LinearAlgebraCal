#include<iostream>
#include<iomanip>
#include<cmath>
#define N 20
using namespace std;
double det(double a[N][N],int n);
void adjoint(double a[N][N],int n);
int main(void)
{
    int n;
    double a[N][N],ad[N][N],D;
    cout<<"���������������İ���������ǳ����\n----------------------------------------\n";
    cout<<"�����뷽��Ľ�����";
    while(cin>>n&&n!='*')
    {
    cout<<"������Ҵ��ϵ��°�˳������ÿ����:"<<endl;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
            cin>>a[i][j];
      }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            ad[i][j]=a[i][j];
    }
	cout<<"����������ʽֵΪ:"<<det(a,n)<<")\n";
    adjoint(ad,n);
    cout<<"���İ�������ǣ�"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<setw(3)<<ad[i][j]<<ends;
        cout<<endl;
    }
    cout<<"\n----------------------------------------\n������������(You can input * to end):";
    }
    return 0;
}


void adjoint(double arr[N][N],int n)
{
    double temp[N][N],c[N][N];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            temp[i][j]=arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=i;k<n-1;k++)
            {
                for(int l=0;l<n;l++)
                {
                    temp[k][l]=temp[k+1][l];
                }

            }
            for(int k=0;k<n-1;k++)
            {
                for(int l=j;l<n-1;l++)
                {
                    temp[k][l]=temp[k][l+1];
                }

            }
                c[i][j]=det(temp,n-1)*pow(-1,i+j+2);
                for(int i=0;i<n;i++)
               {
                   for(int j=0;j<n;j++)
                       temp[i][j]=arr[i][j];
               }
        }
    }
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            arr[i][j]=c[j][i];
    }
}


double det(double a[N][N],int n)
{
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






















