#include<iostream>
#include<iomanip>
#include<cmath>
#define N 20
using namespace std;
double det(double arr[N][N],int n);
void alg_complement(double a[N][N],int n);  //��������ʽ 
void complement_minor(double a[N][N],int n);//����ʽ 

int main(void)
{
    int n;
    double a[N][N],comple[N][N],alg_comple[N][N],D;
    cout<<"�������������ʽ�ʹ�������ʽ(designed by XuZhichao)"<<endl;
    cout<<" Now enjoy it!"<<endl<<endl;
    cout<<"�����������";
    while(cin>>n&&n!='*')
    {
       cout<<"��˳����������ÿһ��:"<<"("<<n<<"*"<<n<<")"<<endl;
       for(int i=0;i<n;i++)
       {
          for(int j=0;j<n;j++)
            cin>>a[i][j];
       }

       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           { 
             comple[i][j]=a[i][j];
             alg_comple[i][j]=a[i][j]; 
             
		   } 
       }
       alg_complement(alg_comple,n);
       complement_minor(comple,n);
       cout<<"����ʽ:"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
              cout<<setw(3)<<comple[i][j]<<ends;
			  cout<<endl;   
       }
	   cout<<endl;
       cout<<"��������ʽ:\n"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
              cout<<setw(3)<<alg_comple[i][j]<<ends;
           cout<<endl;
       }
       

    cout<<endl<<"---------------------------------\n";
    cout<<"�����������* to quit��";
    }
	cout<<"Bye-bye!Good Luck!"<<endl;
 return 0;
}


void complement_minor(double arr[N][N],int n)
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
                c[i][j]=det(temp,n-1);
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
            arr[i][j]=c[i][j];
    }
}


void alg_complement(double arr[N][N],int n)
{
    double temp[N][N],c[N][N];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            temp[i][j]=arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)          //ǰ����ѭ���Ƕ�������ʽ��ÿ��Ԫ�صĲ��� 
        {
            for(int k=i;k<n-1;k++)    //��a[i][j]�����ж����±�һ��Ԫ���滻�����൱�ڰ�a[i][j]�����е�Ԫ�ػ�ȥ 
            {
                for(int l=0;l<n;l++)
                {
                    temp[k][l]=temp[k+1][l];
                }
            }
            for(int k=0;k<n-1;k++)   //��a[i][j]�����ж����ұ�һ��Ԫ���滻�����൱�ڰ�a[i][j]�����е�Ԫ�ػ�ȥ
            {
                for(int l=j;l<n-1;l++)
                {
                    temp[k][l]=temp[k][l+1];
                }
            }                        //��ʱtemp[n-1][n-1]Ϊa[i][j]Ԫ�ص�����ʽ 
            c[i][j]=det(temp,n-1)*pow(-1,i+j+2); //c[i][j]�����������ʽ 
            for(int i=0;i<n;i++)
            {
            	for(int j=0;j<n;j++)
                    temp[i][j]=arr[i][j]; //�ٰ�a����temp���Ա������һ��ѭ�� 
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            arr[i][j]=c[i][j];  //��c[N][N]���鸳ֵ��a[N][N] 
    }
}


double det(double arr[N][N],int n)
{
    double D,a[N][N];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++) 
    	{
    		a[i][j]=arr[i][j];
		}
	}
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





















 
