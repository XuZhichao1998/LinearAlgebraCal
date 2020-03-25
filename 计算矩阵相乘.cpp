#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    int m,n,p,q,i,j,k;
    cout<<"This program is designed by XuZhichao."<<endl;
    cout<<"it can calculate the arithmetic product of two matrices if they are available for multiplying."<<endl<<endl;
    cout<<"请输入矩阵A,B的维数(行数和列数)m n p q:(n必须等于p)\n";
    while(cin>>m>>n>>p>>q&&m!='*')
 {
 	double a[20][20]={0},b[20][20]={0},c[20][20]={0};
	    
   if(n!=p){cout<<"输入错误！请重新输入矩阵A,B的维数(行数和列数)m n p q:(n必须等于p！！！)(或输入*结束)"<<endl;}
   else
   {
    cout<<"请输入矩阵A:("<<m<<"*"<<n<<")\n";
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"请输入矩阵B:("<<p<<"*"<<q<<")\n";
         for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            cin>>b[i][j];
        }
    }


    for(i=0;i<m;i++)
    {
       for(j=0;j<q;j++)
       {
           for(k=0;k<n;k++)
           {
               c[i][j]+=a[i][k]*b[k][j];
           }
       }
    }
    cout<<"矩阵A为：\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<setw(3)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"矩阵B为:\n";
     for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            cout<<setw(3)<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"矩阵A左乘矩阵B得到的新矩阵C为：\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            cout<<setw(3)<<c[i][j]<<" ";
        }
        cout<<endl<<endl<<endl;
    }
    cout<<"你可以继续输入矩阵A,B的维数(行数和列数)m n p q:(n必须等于p)(或输入*结束)\n";
   }

 }cout<<"Bye-bye."<<endl;
    return 0;
}
