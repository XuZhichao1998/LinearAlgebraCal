#include<iostream>
#include<iomanip>
#include<cmath>
#define N 20
using namespace std;
double det(double arr[N][N],int n);
void alg_complement(double a[N][N],int n);  //代数余子式 
void complement_minor(double a[N][N],int n);//余子式 

int main(void)
{
    int n;
    double a[N][N],comple[N][N],alg_comple[N][N],D;
    cout<<"功能是输出余子式和代数余子式(designed by XuZhichao)"<<endl;
    cout<<" Now enjoy it!"<<endl<<endl;
    cout<<"请输入阶数：";
    while(cin>>n&&n!='*')
    {
       cout<<"按顺序输入它的每一项:"<<"("<<n<<"*"<<n<<")"<<endl;
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
       cout<<"余子式:"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
              cout<<setw(3)<<comple[i][j]<<ends;
			  cout<<endl;   
       }
	   cout<<endl;
       cout<<"代数余子式:\n"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
              cout<<setw(3)<<alg_comple[i][j]<<ends;
           cout<<endl;
       }
       

    cout<<endl<<"---------------------------------\n";
    cout<<"输入阶数：（* to quit）";
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
        for(int j=0;j<n;j++)          //前两重循环是对于行列式中每个元素的操作 
        {
            for(int k=i;k<n-1;k++)    //把a[i][j]所在行都用下边一行元素替换掉，相当于把a[i][j]所在行的元素划去 
            {
                for(int l=0;l<n;l++)
                {
                    temp[k][l]=temp[k+1][l];
                }
            }
            for(int k=0;k<n-1;k++)   //把a[i][j]所在列都用右边一列元素替换掉，相当于把a[i][j]所在列的元素划去
            {
                for(int l=j;l<n-1;l++)
                {
                    temp[k][l]=temp[k][l+1];
                }
            }                        //此时temp[n-1][n-1]为a[i][j]元素的余子式 
            c[i][j]=det(temp,n-1)*pow(-1,i+j+2); //c[i][j]储存代数余子式 
            for(int i=0;i<n;i++)
            {
            	for(int j=0;j<n;j++)
                    temp[i][j]=arr[i][j]; //再把a赋给temp，以便进行下一次循环 
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            arr[i][j]=c[i][j];  //把c[N][N]数组赋值给a[N][N] 
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





















 
