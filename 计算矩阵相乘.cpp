#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    int m,n,p,q,i,j,k;
    cout<<"This program is designed by XuZhichao."<<endl;
    cout<<"it can calculate the arithmetic product of two matrices if they are available for multiplying."<<endl<<endl;
    cout<<"���������A,B��ά��(����������)m n p q:(n�������p)\n";
    while(cin>>m>>n>>p>>q&&m!='*')
 {
 	double a[20][20]={0},b[20][20]={0},c[20][20]={0};
	    
   if(n!=p){cout<<"��������������������A,B��ά��(����������)m n p q:(n�������p������)(������*����)"<<endl;}
   else
   {
    cout<<"���������A:("<<m<<"*"<<n<<")\n";
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"���������B:("<<p<<"*"<<q<<")\n";
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
    cout<<"����AΪ��\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<setw(3)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"����BΪ:\n";
     for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            cout<<setw(3)<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"����A��˾���B�õ����¾���CΪ��\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            cout<<setw(3)<<c[i][j]<<" ";
        }
        cout<<endl<<endl<<endl;
    }
    cout<<"����Լ����������A,B��ά��(����������)m n p q:(n�������p)(������*����)\n";
   }

 }cout<<"Bye-bye."<<endl;
    return 0;
}
