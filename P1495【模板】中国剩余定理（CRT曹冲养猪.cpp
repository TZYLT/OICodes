#include<bits/stdc++.h>
using namespace std;
#include<cstdio>
long long n,a[16],m[16],Mi[16],mul=1,X;
inline int read() {
	int io=0;
	char in=getchar();
	while(in<'0'||in>'9')in=getchar();
	while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
	return io;
}
void exgcd(long long a,long long b,long long &x,long long &y) {
	if(b==0) {x=1;y=0;return ;}
	exgcd(b,a%b,x,y);
	int z=x;
	x=y;
	y=z-y*(a/b);
}
int main() {
	n=read();
	for(int t=1; t<=n; ++t) {
		int M=read();
		m[t]=M;
		mul*=M;
		a[t]=read();
	}
	for(int t=1; t<=n; ++t) {
		Mi[t]=mul/m[t];
		long long x=0,y=0;
		exgcd(Mi[t],m[t],x,y);
		X+=a[t]*Mi[t]*(x<0?x+m[t]:x);
	}
	printf("%lld",X%mul);
	return 0;
}
