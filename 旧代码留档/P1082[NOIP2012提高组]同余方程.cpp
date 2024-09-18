#include<bits/stdc++.h>
using namespace std;
void exgcd(int a,int b,int &x,int &y){
	//printf("[%d,%d]",a,b);
	if(a%b==0){x=0;y=1;return;}
	exgcd(b,a%b,x,y);
	int z=x;
	x=y;
	y=z-(int)a/b*y;
}
int a,b,x,y;
int main(){
	scanf("%d%d",&a,&b);
	exgcd(a,b,x,y);
	printf("%d\n",(x+b)%b);
}
