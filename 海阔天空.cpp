#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
double cal(double x,double p){
    return (60000.0*x/p);
}
// 1=F
double shift(int x,int bd){
    if(x==0)return 0;
    if(x==1)x=6;
    else if(x==2)x=8;
    else if(x==3)x=10;
    else if(x==4)x=12;
    else if(x==5)x=13;
    else if(x==6)x=15;
    else if(x==7)x=17;

    return (double)261.6*pow(2,(1.0/12.0)*x+bd);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cout<<"������ ��ҹ�￴ѩƮ��"<<endl;
    Beep(shift(3,0),cal(0.5,60));
    Beep(shift(2,0),cal(0.25,60));
    Beep(shift(1,0),cal(0.25,60));
    
    Beep(shift(1,0),cal(2.25,60));
    Beep(0,cal(0.5,60));
    Beep(shift(3,0),cal(0.25,60));
    Beep(shift(4,0),cal(0.25,60));

    Beep(shift(5,0),cal(0.5,60));
    Beep(shift(5,0),cal(0.25,60));
    Beep(shift(5,0),cal(0.75,60));
    Beep(shift(6,0),cal(0.25,60));
    Beep(shift(5,0),cal(0.25,60));
    Beep(shift(5,0),cal(1.5,60));
    cout<<"������ȴ�˵�����ƮԶ��"<<endl;
    Beep(shift(6,0),cal(0.25,60));
    Beep(shift(7,0),cal(0.25,60));
    Beep(shift(1,1),cal(0.5,60));
    Beep(shift(1,1),cal(0.25,60));
    Beep(shift(1,1),cal(0.75,60));
    Beep(shift(1,1),cal(0.5,60));
    Beep(shift(1,1),cal(0.5,60));
    Beep(shift(7,0),cal(0.5,60));
    Beep(shift(6,0),cal(0.25,60));
    Beep(shift(5,0),cal(0.75,60));
    Beep(shift(6,0),cal(2.5,60));
    cout<<"������׷��"<<endl;
    Beep(shift(6,0),cal(0.5,60));
    Beep(shift(5,0),cal(0.5,60));
    Beep(shift(5,0),cal(1.5,60));
    Beep(shift(5,0),cal(0.5,60));
    Beep(shift(3,0),cal(0.25,60));
    Beep(shift(2,0),cal(0.25,60));
    Beep(shift(1,0),cal(0.5,60));
    cout<<"����ֲ���Ӱ��"<<endl;
    Beep(shift(3,0),cal(0.5,60));
    Beep(shift(4,0),cal(0.5,60));
    Beep(shift(3,0),cal(0.5,60));
    Beep(shift(2,0),cal(0.5,60));
    Beep(shift(2,0),cal(0.5,60));
    Beep(shift(3,0),cal(0.25,60));
    Beep(shift(2,0),cal(0.75,60));
    cout<<"��պ��������� �ɻ�� (˭û�ڱ�)"<<endl;
    Beep(shift(3,0),cal(0.5,60));
    Beep(shift(2,0),cal(0.25,60));
    Beep(shift(2,0),cal(0.75,60));
    Beep(shift(1,0),cal(0.5,60));
    Beep(shift(1,0),cal(0.5,60));
    Beep(shift(1,0),cal(0.25,60));
    Beep(shift(1,0),cal(0.75,60));
    Beep(shift(2,0),cal(0.5,60));
    Beep(shift(1,0),cal(0.5,60));
    Beep(shift(1,0),cal(0.5,60));
    Beep(shift(5,0),cal(0.5,60));
    Beep(shift(6,0),cal(0.5,60));
    Beep(shift(7,0),cal(0.5,60));
    Beep(shift(1,1),cal(0.5,60));

}