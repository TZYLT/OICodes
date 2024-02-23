#include<bits/stdc++.h>
using namespace std;
int inv[2002050];
int n,p,a,b;
void write(long long x) {
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main() {
	inv[1]=1;
	scanf("%d%d",&n,&p);
	for(int i=2;i<=n;++i)
		inv[i]=(long long)(p-p/i)*inv[p%i]%p;
	for(int i=1; i<=n; i++)
		write(inv[i]),putchar('\n');
}
