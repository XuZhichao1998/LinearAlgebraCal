#include<iostream>
using namespace std;
const  int Max=50; 
int main()
{
	int n;double a[Max];
	cout<<"����������������n: ";
	while(cin>>n)
	{
	   cout<<"�밴˳������"<<n<<"����\n"; 
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
	   if(number%2==0)cout<<"ż����\t";
	   else cout<<"������\t";
	   cout<<"������Ϊ��"<<number<<endl;
	   cout<<endl<<"����������������n: ";
	}
	
	return 0;
	
}
