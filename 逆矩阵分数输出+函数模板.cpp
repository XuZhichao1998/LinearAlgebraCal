#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstring>
#define N 20
#define minn 1e-6
using namespace std;
int max_common_diviser(int a,int b)
{
	int temp=max(a,b);
	if(a<b){b=a;a=temp;}
	int mod=a%b;
	while(mod!=0)
	{
		a=b;b=mod;
		mod=a%b;
	}
	//if(b<0)b=-b;
	return b;
}
struct fraction{   //分数
    int mother;
    int son;
};
double Det(double a[N][N],int n)
{
	if(n==1)return a[0][0];
	if(n==2)return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
	if(n>2){
		double b[N][N]={0},answer=0.0;
		int i,j,k,l;
		for(i=0;i<n;i++){
			for(j=0;j<n-1;j++){
				for(k=0;k<n-1;k++){
					if(k<i) b[j][k]=a[j+1][k];
					else    b[j][k]=a[j+1][k+1];

				}
			}
			answer+=Det(b,n-1)*pow(-1,i)*a[0][i];
		}
		return answer;
	}
}

void adjoint(double arr[N][N],int n) // 该函数的功能是把方阵变为它的伴随矩阵
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
                c[i][j]=Det(temp,n-1)*pow(-1,i+j+2);
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
void adjoint_reserve_Det(void)
{
	int n;
    double a[N][N],ad[N][N],inverse[N][N],D;
    printf("请输入要求逆矩阵的方阵阶数(>=2)：");
    while(cin>>n)
    {
        memset(a,0,sizeof(a));memset(ad,0,sizeof(ad));memset(inverse,0,sizeof(inverse));
        printf("请按顺序输入这个%d阶方阵的每一个元素:\n",n);
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
        adjoint(ad,n);
        printf("它的伴随矩阵如下:\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<setw(6)<<ad[i][j]<<ends;
            cout<<endl;
        }
        D=Det(a,n);
        printf("输入方阵的行列式是:%.3lf\n",D);
        if(D==0)cout<<"（行列式为0，不可逆！）It don't have its corresponding inverse matrix."<<endl;
        else
        {
            /*for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    inverse[i][j]=ad[i][j]/D;
            }
            printf("它的逆矩阵为：\n");
            for(int i=0;i<n;i++)
           {
            for(int j=0;j<n;j++)
                cout<<setw(10)<<inverse[i][j]<<ends;
            cout<<endl;
           }*/
           printf("逆矩阵为：\n");
           fraction nijuzhen[N][N];
           int max_div;
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<n;j++)
               {
                   nijuzhen[i][j].mother=D;
                   nijuzhen[i][j].son=ad[i][j];
                   if(nijuzhen[i][j].son!=0){
                   		max_div=max_common_diviser(ad[i][j],D);
                   		nijuzhen[i][j].mother/=max_div;
                  		nijuzhen[i][j].son/=max_div;
                   		if(nijuzhen[i][j].mother*nijuzhen[i][j].son<0){
                        	nijuzhen[i][j].mother=abs(nijuzhen[i][j].mother);
                        	nijuzhen[i][j].son=-1*abs(nijuzhen[i][j].son);
                   		}
               		}
                   if(nijuzhen[i][j].son==0)/*cout<<setw(6)<<nijuzhen[i][j].son<<"  ";*/cout<<setiosflags(ios::fixed)<<setiosflags(ios::left)<<setw(6)<<0<<"  ";
                   else if(nijuzhen[i][j].mother==1)cout<<setiosflags(ios::fixed)<<setiosflags(ios::left)<<setw(6)<<nijuzhen[i][j].son<<"  ";
                   else cout<<nijuzhen[i][j].son<<"/"<<setiosflags(ios::fixed)<<setiosflags(ios::left)<<setw(6)<<nijuzhen[i][j].mother<<"  ";
               }
               cout<<endl;
           }

        }
        cout<<endl;
        int flagg;
        printf("继续求逆矩阵按1，否则按0：");
        cin>>flagg;
        if(flagg!=1)break;
        printf("请输入要求逆矩阵的方阵阶数(>=2):");
    }
}
int main()
{
	adjoint_reserve_Det();
	return 0;
}
























