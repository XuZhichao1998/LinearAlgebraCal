/*      **2018.1.9 ���ǳ�**
**���ܣ�����ֻ��������X��һ�����**
**�Ľ׾�������ʽ��X^4��ϵ��**/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=20;
int inverse_number_4(int a,int b,int c,int d);
int main(void)
{
    cout<<"Designed by ���ǳ�.2018.1.9\n";
	int a[N][N]={0},s=0,s1=0;
	printf("������4*4�ľ���(��X����ϵ����û�е���0)��\n");
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
							if(s1)cout<<"��"<<i++<<"�"<<"a[1"<<b+1<<"]*"<<"a[2"<<c+1<<"]*"<<"a[3"<<d+1<<"]*"<<"a[4"<<e+1<<"]="<<
							 a[0][b]<<"*"<<a[1][c]<<"*"<<a[2][d]<<"*"<<a[3][e]<<"*"<<inverse_number_4(b,c,d,e)<<"="<<s1<<endl;
						}
					}
                }
            }
        }
		cout<<"X���Ĵ����ϵ���ǣ�"<<s<<endl;
		cout<<"---------------------------------------------------\n";
		printf("������4*4�ľ���(��X����ϵ����û�е���0)(*����)��\n");
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
