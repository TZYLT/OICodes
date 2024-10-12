#include<bits/stdc++.h>
using namespace std;
#define MAXN 110
int n,m,k;
struct matrix {
	int dat[MAXN][MAXN];
	matrix() {
		memset(dat,0x3f,sizeof(dat));
	}
	inline int* operator [](const int i) {
		return dat[i];
	}
} g;
inline int min(int a,int b) {
	return a<b ? a : b;
}
matrix operator *(matrix &a,matrix &b) {
	matrix c;
	for (register int i=1;i<=n;i++) {
		for (register int j=1;j<=n;j++) {
			for (register int k=1;k<=n;k++) {
				c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
			}
		}
	}
	return c;
}
matrix mpow(matrix a,int n) { 
	matrix ans=a;
	for (n--;n;a=a*a,n>>=1) {
		if (n&1) ans=ans*a;
	}
	return ans;
}
int main() {
	int s,t;
	scanf("%d%d%d%d",&k,&m,&s,&t);
	int id[1010]={};
	for (int i=0;i<m;i++) {
		int u,v,w;
		scanf("%d%d%d",&w,&u,&v);
		u=id[u] ? id[u] : id[u]=++n;
		v=id[v] ? id[v] : id[v]=++n;
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	s=id[s];
	t=id[t];
	matrix ans=mpow(g,k);
	printf("%d\n",ans[s][t]);
	return 0;
}