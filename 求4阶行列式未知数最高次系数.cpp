/*      **2018.1.9 许智超**
**功能：计算只含常数和X的一次项的**
**四阶矩阵行列式中X^4的系数**/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=20;
int inverse_number_4(int a,int b,int c,int d);
int main(void)
{
    cout<<"Designed by 许智超.2018.1.9\n";
	int a[N][N]={0},s=0,s1=0;
	printf("请输入4*4的矩阵(有X的输系数，没有的输0)：\n");
	while(1)
	{
	    cout<<"---------------------------------------------------\n";
		int i=1;s=0;
		memset(a,0,sizeof(a));
	 	for(int i=0;i<4;i++)
	 		for(int j=0;j<4;j++)
	 			scanf("%d",&a[i][j]);
		for(int b=0;b<4;b++)
        {
			for(int c=0;c<4;c++)
            {
				for(int d=0;d<4;d++)
				{
					for(int e=0;e<4;e++)
					{
						if((c-b)*(d-b)*(e-b)*(d-c)*(c-e)*(d-e))
						{
							//cout<<b+1<<c+1<<d+1<<e+1<<"="<<a[0][b]<<" "<<a[1][c]<<" "<<a[2][d]<<" "<<a[3][e]<<endl;
							s1=a[0][b]*a[1][c]*a[2][d]*a[3][e]*inverse_number_4(b,c,d,e);
							s+=s1;
							if(s1)cout<<"第"<<i++<<"项："<<"a[1"<<b+1<<"]*"<<"a[2"<<c+1<<"]*"<<"a[3"<<d+1<<"]*"<<"a[4"<<e+1<<"]="<<
							 a[0][b]<<"*"<<a[1][c]<<"*"<<a[2][d]<<"*"<<a[3][e]<<"*"<<inverse_number_4(b,c,d,e)<<"="<<s1<<endl;
						}
					}
                }
            }
        }
		cout<<"X的四次项的系数是："<<s<<endl;
		cout<<"---------------------------------------------------\n";
		printf("请输入4*4的矩阵(有X的输系数，没有的输0)(*结束)：\n");
	}
	return 0;
}
int inverse_number_4(int a,int b,int c,int d)
{
	int arr[4]={0},num=0;
	arr[0]=a;arr[1]=b;arr[2]=c;arr[3]=d;
	for(int i=1;i<4;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]<arr[j])num++;
		}
	}
	if(num%2==0)return 1;
	else return (-1);
}
