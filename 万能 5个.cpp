#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstring>
#define N 20
#define minn 1e-6
using namespace std;
const int L=60;
const double PI=atan(1.0)*4;
int max_common_diviser(int a,int b)//�������
{
	int temp=max(a,b);
	if(a<b)
	{
		b=a;
		a=temp;
	}
	int mod=a%b;
	while(mod!=0)
	{
		a=b;
		b=mod;
		mod=a%b;
	}
	return b;
}
struct fraction    //����
{
	int mother;
	int son;
};
double Det(double a[N][N],int n)//����ʽ��������)
{
	if(n==1)return a[0][0];
	if(n==2)return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
	if(n>2)
	{
		double b[N][N]= {0},answer=0.0;
		int i,j,k,l;
		for(i=0; i<n; i++)
		{
			for(j=0; j<n-1; j++)
			{
				for(k=0; k<n-1; k++)
				{
					if(k<i) b[j][k]=a[j+1][k];
					else    b[j][k]=a[j+1][k+1];

				}
			}
			answer+=Det(b,n-1)*pow(-1,i)*a[0][i];
		}
		return answer;
	}
}

void Det_n(void)//��������ʽ����ģ��
{
	int n,flag;
	double a[N][N]= {0},answer=0.0;
	printf("������Ҫ��������ʽ�Ľ�����");
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		printf("������ʽ \n");
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%lf",&a[i][j]);
		answer=Det(a,n);
		cout<<answer<<endl;
		printf("---------------------------------------------\n");
		printf("����������ʽ�밴1������0��");
		cin>>flag;
		if(flag!=1)break;
		printf("���������Ҫ��������ʽ�Ľ�����");
	}
}

void matrix_product(void)//���������˺���ģ��
{
	typedef double arr[N][N];
	arr a,b,c;
	int m,n,p,q,i,j,k,flag;
	printf("���������A(m*n)�;���B(p*q)��m,n,p,q��\n");
	//while(scanf("%d%d%d%d",&m,&n,&p,&q)!=EOF)
	while(cin>>m>>n>>p>>q)
	{
		if(n!=p)
		{
			printf("n������p,�޷��ˣ�����������m,n,p,q��\n");
			continue;
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		printf("�밴˳���������A(%d*%d)��\n",m,n);
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				scanf("%lf",&a[i][j]);
		printf("�밴˳���������B(%d*%d)��\n",p,q);
		for(i=0; i<p; i++)
			for(j=0; j<q; j++)
				scanf("%lf",&b[i][j]);
		for(i=0; i<m; i++)
			for(j=0; j<q; j++)
				for(k=0; k<n; k++)
					c[i][j]+=a[i][k]*b[k][j];
		printf("����ľ���A(%d*%d)Ϊ��\n",m,n);
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
				cout<<setw(8)<<a[i][j];
			cout<<endl;
		}
		printf("����ľ���BΪ(%d*%d)��\n",p,q);
		for(i=0; i<p; i++)
		{
			for(j=0; j<q; j++)
				cout<<setw(8)<<b[i][j];
			cout<<endl;
		}
		printf("����A(%d*%d)��˾���B(%d*%d)���õľ���C(%d*%d)Ϊ��\n",m,n,p,q,m,q);
		for(i=0; i<m; i++)
		{
			for(j=0; j<q; j++)
				cout<<setw(8)<<c[i][j];
			cout<<endl;
		}
		printf("---------------------------------------------\n");
		printf("���������������밴1������0��");
		cin>>flag;
		if(flag!=1)break;
		printf("������m,n,p,q ��\n");

	}
}
void adjoint(double arr[N][N],int n) // �ú����Ĺ����ǰѷ��󣨸����ͣ���Ϊ���İ������
{
	double temp[N][N],c[N][N];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			temp[i][j]=arr[i][j];
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=i; k<n-1; k++)
			{
				for(int l=0; l<n; l++)
				{
					temp[k][l]=temp[k+1][l];
				}

			}
			for(int k=0; k<n-1; k++)
			{
				for(int l=j; l<n-1; l++)
				{
					temp[k][l]=temp[k][l+1];
				}

			}
			c[i][j]=Det(temp,n-1)*pow(-1,i+j+2);
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
					temp[i][j]=arr[i][j];
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			arr[i][j]=c[j][i];
	}
}
void adjoint_reserve_Det(void)//���������ģ��(������ʽ���)
{
	int n;
	double a[N][N],ad[N][N],inverse[N][N],D;
	printf("������Ҫ�������ķ������(>=2)��");
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(ad,0,sizeof(ad));
		memset(inverse,0,sizeof(inverse));
		printf("�밴˳���������%d�׷����ÿһ��Ԫ��:\n",n);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cin>>a[i][j];
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				ad[i][j]=a[i][j];
		}
		adjoint(ad,n);
		printf("���İ����������:\n");
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cout<<setprecision(4)<<setw(6)<<ad[i][j]<<ends;
			cout<<endl;
		}
		D=Det(a,n);
		printf("���뷽�������ʽ��:%.3lf\n",D);
		if(D==0)cout<<"������ʽΪ0�������棡��It don't have its corresponding inverse matrix."<<endl;
		else
		{
			/*for(int i=0;i<n;i++)
			{
			    for(int j=0;j<n;j++)
			        inverse[i][j]=ad[i][j]/D;
			}
			printf("���������Ϊ��\n");
			for(int i=0;i<n;i++)
			{
			for(int j=0;j<n;j++)
			    cout<<setw(10)<<inverse[i][j]<<ends;
			cout<<endl;
			}*/
			printf("�����Ϊ��\n");
			fraction nijuzhen[N][N];
			int max_div;
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					nijuzhen[i][j].mother=D;
					nijuzhen[i][j].son=ad[i][j];
					if(nijuzhen[i][j].son!=0)
					{
						max_div=max_common_diviser(ad[i][j],D);
						nijuzhen[i][j].mother/=max_div;
						nijuzhen[i][j].son/=max_div;
						if(nijuzhen[i][j].mother*nijuzhen[i][j].son<0)
						{
							nijuzhen[i][j].mother=abs(nijuzhen[i][j].mother);
							nijuzhen[i][j].son=-1*abs(nijuzhen[i][j].son);
						}
					}
					if(nijuzhen[i][j].son==0)/*cout<<setw(6)<<0<<"  ";*/cout<<setiosflags(ios::fixed)<<setiosflags(ios::left)<<setw(6)<<0<<"  ";
					else if(nijuzhen[i][j].mother==1)cout<<setiosflags(ios::fixed)<<setiosflags(ios::left)<<setw(6)<<nijuzhen[i][j].son<<"  ";
					else cout<<nijuzhen[i][j].son<<"/"<<setiosflags(ios::fixed)<<setiosflags(ios::left)<<setw(6)<<nijuzhen[i][j].mother<<"  ";
				}
				cout<<endl;
			}

		}
		cout<<endl;
		int flagg;
		printf("---------------------------------------------\n");
		printf("�����������1������0��");
		cin>>flagg;
		if(flagg!=1)break;
		printf("������Ҫ�������ķ������(>=2):");
	}
}

int det(int arr[N][N],int n)//������ʽ���������ͣ�
{
	int D,a[N][N]= {0};
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			a[i][j]=arr[i][j];
	}
	if(n==1)
	{
		D=a[0][0];
		return D;
	}
	if(n==2)
	{
		D=a[0][0]*a[1][1]-a[0][1]*a[1][0];
		return D;
	}
	if(n>=3)
	{
		D=0.0;
		int line1[N];
		int temp[N][N];
		for(int i=0; i<n; i++)
		{
			line1[i]=a[i][0]*pow(-1,i+2);
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n-1; j++)
			{
				temp[i][j]=a[i][j+1];
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int r=i; r<n-1; r++)
			{
				for(int c=0; c<n; c++)
				{
					a[r][c]=temp[r+1][c];
				}
			}
			D+=line1[i]*det(a,n-1);
			for(int i=0; i<n-1; i++)
			{
				for(int j=0; j<n; j++)
					a[i][j]=temp[i][j];
			}
		}
		return D;
	}
}

void int_adjoint(int arr[N][N],int n)//�ѷ���(����)��Ϊ���İ������
{
	int temp[N][N],c[N][N];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			temp[i][j]=arr[i][j];
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=i; k<n-1; k++)
			{
				for(int l=0; l<n; l++)
				{
					temp[k][l]=temp[k+1][l];
				}
			}

			for(int k=0; k<n-1; k++)
			{
				for(int l=j; l<n-1; l++)
				{
					temp[k][l]=temp[k][l+1];
				}
			}

			c[i][j]=det(temp,n-1)*pow(-1,i+j+2);
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
					temp[i][j]=arr[i][j];
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			arr[i][j]=c[j][i];
	}
}
void mod_26(int arr[N][N],int mm,int nn)//��m*n�׵��������鶼����26ȡ��(��Ϊ��)
{
	for(int i=0; i<mm; i++)
		for(int j=0; j<nn; j++)
		{
			arr[i][j]=arr[i][j]%26;
			if(arr[i][j]<0) arr[i][j]+=26;
		}

}
void matrix(int mat1[N][N],int mat2[N][N],int product[N][N],int m,int n,int p,int q)//������˺���
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<q; j++)
		{
			for(int k=0; k<n; k++)
			{
				product[i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
	}
}
void Hill_cipher(void)//ϣ������ ����ģ��
{
	cout<<"ϣ������ļ�������ܡ�"<<endl<<"--------------------------------------------\n";
	int flag;
	cout<<"����������1������������0��";
	while(cin>>flag)
	{
		if(flag==2)break;
		if(flag!=0&&flag!=1)
		{
			cout<<"������󣡼�������1����������0�����������룺";
			continue;
		}
		int key[N][N]= {0},cryp[L]= {0};
		char ch[L];
		int n;
		cout<<"��������Կ���󣨷��󣩵Ľ���n:";
		cin>>n;
		if(flag)cout<<"���������ģ�"<<endl;
		else cout<<"���������ģ�"<<endl;
		cin>>ch;

		cout<<"��������Կ���󣨷���:("<<n<<"*"<<n<<")"<<endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cin>>key[i][j];
		}
		if(flag==0)
		{
			int key1[N][N];
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
					key1[i][j]=key[i][j];
			}

			int D=det(key1,n);
			int D1;
			if(D==1) D1=1;
			if(D==3)  D1=9;
			if(D==5)  D1=21;
			if(D==7)  D1=15;
			if(D==9)  D1=3;
			if(D==11) D1=19;
			if(D==15) D1=7;
			if(D==17) D1=23;
			if(D==19) D1=11;
			if(D==21) D1=5;
			if(D==23) D1=17;
			if(D==25) D1=25;

			int_adjoint(key,n);

			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					key[i][j]*=D1;
				}
			}
		}
		mod_26(key,n,n);

		int leng=strlen(ch);
		for(int i=0; i<leng; i++)
		{
			if(ch[i]=='A')cryp[i]=1;
			if(ch[i]=='B')cryp[i]=2;
			if(ch[i]=='C')cryp[i]=3;
			if(ch[i]=='D')cryp[i]=4;
			if(ch[i]=='E')cryp[i]=5;
			if(ch[i]=='F')cryp[i]=6;
			if(ch[i]=='G')cryp[i]=7;
			if(ch[i]=='H')cryp[i]=8;
			if(ch[i]=='I')cryp[i]=9;
			if(ch[i]=='J')cryp[i]=10;
			if(ch[i]=='K')cryp[i]=11;
			if(ch[i]=='L')cryp[i]=12;
			if(ch[i]=='M')cryp[i]=13;
			if(ch[i]=='N')cryp[i]=14;
			if(ch[i]=='O')cryp[i]=15;
			if(ch[i]=='P')cryp[i]=16;
			if(ch[i]=='Q')cryp[i]=17;
			if(ch[i]=='R')cryp[i]=18;
			if(ch[i]=='S')cryp[i]=19;
			if(ch[i]=='T')cryp[i]=20;
			if(ch[i]=='U')cryp[i]=21;
			if(ch[i]=='V')cryp[i]=22;
			if(ch[i]=='W')cryp[i]=23;
			if(ch[i]=='X')cryp[i]=24;
			if(ch[i]=='Y')cryp[i]=25;
			if(ch[i]=='Z')cryp[i]=0;
		}

		int q = (leng+n-1)/n;
		int crm[N][N]= {0};
		int k1=0;
		for(int j=0; j<q; j++)
		{
			for(int i=0; i<n; i++)
			{
				crm[i][j] = cryp[k1];
				k1++;
			}
		}

		int product[N][N]= {0};
		matrix(key,crm,product,n,n,n,q);
		mod_26(product,n,q);

		int k2=0;
		char ch2[L];
		for(int j=0; j<q; j++)
		{
			for(int i=0; i<n; i++)
			{
				if(product[i][j]==1)ch2[k2] ='A';
				if(product[i][j]==2)ch2[k2] ='B';
				if(product[i][j]==3)ch2[k2] ='C';
				if(product[i][j]==4)ch2[k2] ='D';
				if(product[i][j]==5)ch2[k2] ='E';
				if(product[i][j]==6)ch2[k2] ='F';
				if(product[i][j]==7)ch2[k2] ='G';
				if(product[i][j]==8)ch2[k2] ='H';
				if(product[i][j]==9)ch2[k2] ='I';
				if(product[i][j]==10)ch2[k2]='J';
				if(product[i][j]==11)ch2[k2]='K';
				if(product[i][j]==12)ch2[k2]='L';
				if(product[i][j]==13)ch2[k2]='M';
				if(product[i][j]==14)ch2[k2]='N';
				if(product[i][j]==15)ch2[k2]='O';
				if(product[i][j]==16)ch2[k2]='P';
				if(product[i][j]==17)ch2[k2]='Q';
				if(product[i][j]==18)ch2[k2]='R';
				if(product[i][j]==19)ch2[k2]='S';
				if(product[i][j]==20)ch2[k2]='T';
				if(product[i][j]==21)ch2[k2]='U';
				if(product[i][j]==22)ch2[k2]='V';
				if(product[i][j]==23)ch2[k2]='W';
				if(product[i][j]==24)ch2[k2]='X';
				if(product[i][j]==25)ch2[k2]='Y';
				if(product[i][j]==0)ch2[k2] ='Z';
				k2++;
			}

		}
		if(flag==0)
			cout<<"�����������Ϊ��";
		else cout<<"���ܺ������Ϊ��";
		for(int i=0; i<leng; i++)
			cout<<ch2[i];
		cout<<endl<<"--------------------------------"<<endl<<endl;
		cout<<"�����������������1������������0(�˳�������2):";

	}
}

struct coordinate//����
{
	double x,y;
};
double angle(double x,double y)//����ԭ����ĳ�������ɵ����ߵ���ǣ�0-2PI��
{
	double angle=atan(y/x)/PI;
	if(x<0)angle++;
	if(x>=0&&y<0)angle+=2;
	return angle;
}
double s_trangle(double x1,double y1,double x2,double y2)//������ʽ�������������ߵ�������Ӧ�����ε����
{
	double s;
	s=(x1*y2-x2*y1)/2;
	if(s<0)s*=-1;
	return(s);
}

void Area_n_xy(void)
{
	int n;
	cout<<"���������εı���n(n>2)��";
	while(cin>>n)
	{
		if(n<=2)
		{
			cout<<"����������ڶ������������룺";
			continue;
		}
		coordinate zuobiao[n];
		cout<<"������"<<n<<"�����꣺\n";
		for(int i=0; i<n; i++)
		{
			cin>>zuobiao[i].x>>zuobiao[i].y;
		}

		double x0=zuobiao[0].x,y0=zuobiao[0].y;//������ĵ�һ��һ��������긳��(x0,y0)
		for(int i=0; i<n; i++)
		{
			zuobiao[i].x-=x0;
			zuobiao[i].y-=y0;//�൱�ڰѶ��������ƽ�ƣ�ʹ��x0,y0���Ƶ�ԭ�㣬�������е����λ�ò���
		}

		for(int i=1; i<n-1; i++)                      //����ĳ�������ԭ�������ɵ�ֱ���������
		{
			for(int j=i+1; j<n; j++)
			{
				if(angle(zuobiao[i].x,zuobiao[i].y)>angle(zuobiao[j].x,zuobiao[j].y))
				{
					coordinate temp=zuobiao[i];
					zuobiao[i]=zuobiao[j];
					zuobiao[j]=temp;
				}
			}
		}
		double area=0.0;
		for(int i=1; i<n-1; i++)
		{
			area+=s_trangle(zuobiao[i].x,zuobiao[i].y,zuobiao[i+1].x,zuobiao[i+1].y);
		}
		cout<<"���͹"<<n<<"���ε�����ǣ�";
		printf("%.10lf\n������λС����Ľ���ǣ�%.3lf\n",area,area);
		printf("---------------------------------------------------------------\n");
		int flagg;
		printf("��������������밴1������0��");
		cin>>flagg;
		if(flagg!=1)break;
		printf("���������εı���n(n>2)��");
	}
}
int main(void)
{
	int number;
	printf("Designed by XZC.Enjoy it!\n");
	printf("-------------------------------------------------------------\n");
	cout<<"��������ʽ��1���������˰�2���������3��ϣ��������ܽ��ܰ�4����֪������͹����������5\n";
	while(cin>>number)
	{
		switch(number)
		{
			case 1:
				Det_n();
				break;
			case 2:
				matrix_product();
				break;
			case 3:
				adjoint_reserve_Det();
				break;
			case 4:
				Hill_cipher();
				break;
			case 5:
				Area_n_xy();
				break;
			default:
				printf("�������\n");
				break;
		}
		printf("-------------------------------------------------------------\n");
		cout<<"��������ʽ��1���������˰�2���������3;ϣ��������ܽ��ܰ�4����֪������͹����������5\n";
	}



	return 0;
}
