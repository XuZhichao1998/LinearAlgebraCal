#include <iostream>
using namespace std;
int main()
{
    while(1)
    {


    int a1,a2,a3,a4,b1,b2,b3,b4,c1,c2,c3,c4,d1,d2,d3,d4,A1,A2,A3,A4,D;
    cin>>a1>>a2>>a3>>a4;

    cin>>b1>>b2>>b3>>b4;

    cin>>c1>>c2>>c3>>c4;

    cin>>d1>>d2>>d3>>d4;
    cout<<endl;
    A1 = b2*c3*d4 + c2*d3*b4 + d2*b3*c4 - d2*c3*b4 - c2*b3*d4 - b2*d3*c4;
    A2 = b1*c3*d4 + c1*d3*b4 + d1*b3*c4 - d1*c3*b4 - c1*b3*d4 - b1*d3*c4;
    A3 = b1*c2*d4 + c1*d2*b4 + d1*b2*c4 - d1*c2*b4 - c1*b2*d4 - b1*d2*c4;
    A4 = b1*c2*d3 + c1*d2*b3 + d1*b2*c3 - d1*c2*b3 - c1*b2*d3 - b1*d2*c3;
    D  = a1*A1 - a2*A2 + a3*A3 - a4*A4;
    cout<<"A1="<<A1<<ends<<"A2="<<A2<<ends<<"A3="<<A3<<ends<<"A4="<<A4<<endl;
    cout<<"D="<<D<<endl;
   }

    return 0;
}
