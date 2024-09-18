#include<bits/stdc++.h>
using namespace std;
int f[100100][32],fa[100100][32],fb[100100][32],n,h[100100];
#define d[x][y] abs(h[x]-h[y])
void init(){
	
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	init();
}
