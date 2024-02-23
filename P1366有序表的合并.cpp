#include <bits/stdc++.h>
using namespace std;
uint64_t read() {
	uint64_t x = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		x = x*10+ch-'0', ch = getchar();
	return x;
}
uint64_t a[10000001], b[10000001];
int main() {
	for (int T=read(),n,m;(T--)&&(n = read(),m=read());){
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=m;i++)b[i]=read();
		int j=1,temp=0,ans=0;
		for(int i=1;i<=n;i++){
			temp=0;
			while(j<=m&&a[i]>=b[j]){
				temp+=(a[i]==b[j]);
				j++;
			}
			ans^=temp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
