#include<cstdio>
using namespace std;
long long a,b,c,x,y,d;
int exgcd(int a,int b){
	if(b==0){x=1;y=0;return a;}
	int tmp=exgcd(b,a%b);
	int t=x;
	x=y;y=t-a/b*y;
	return tmp;
}
int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	c=-c;
	int d=exgcd(a,b);
	if(c%d!=0){printf("-1\n");return 0;}
	x=c/d*x;
	y=c/d*y;
	printf("%lld %lld\n",x,y);
}