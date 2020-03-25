#include<iostream>
using namespace std;
const  int Max=50; 
int main()
{
	int n;double a[Max];
	cout<<"输入排列中数个数n: ";
	while(cin>>n)
	{
	   cout<<"请按顺序输入"<<n<<"个数\n"; 
	   int number=0;
	   for(int i=0;i<n;i++)
	   cin>>a[i];
	   for(int i=1;i<n;i++)
	   {
		   for(int j=0;j<i;j++)
		   {
			   if(a[i]<a[j])number++;
		   }
	   }
	   if(number%2==0)cout<<"偶排列\t";
	   else cout<<"奇排列\t";
	   cout<<"逆序数为："<<number<<endl;
	   cout<<endl<<"输入排列中数个数n: ";
	}
	
	return 0;
	
}
