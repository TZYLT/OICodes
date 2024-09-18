 #include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include <unistd.h>
#include <windows.h>
using namespace std;
int main()
{
	int i,h;
	long double a,b,c,d=0;
	cout<<"���������";
	cin>>a;
	cout<<"����������Ϣ��%����";
	cin>>c; 
	cout<<"��������Ϣ����"; 
	cin>>h;
	for(i=1;i<=h;i++)
	{
        d=a;
		b=a;
		b/=100;
		b*=c;
		a+=b;
		cout<<"Ϣ����"<<i<<' '<<"�軹���:"<<a<<"Ԫ"<<' '<<"������Ϣ��"<<a-d<<"Ԫ"<<endl;	
		Sleep(10);
	}
   	return 0;
}
