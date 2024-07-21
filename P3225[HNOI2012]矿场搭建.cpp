#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
#define int long long
const int M = 505;
int n,m;
int Num,G,Ans,num,Fcut,Cut,root,count;
int dfn[M],low[M],vis[M];
bool ic[M];
vector<int> g[M];
void Init() {
	n=0;
	num=0;
	Num=0;
	G=1;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	memset(ic,false,sizeof(ic));
	for(int i=1; i<=M; i++)
		g[i].clear();
}
void tarjan(int u,int fa) {
	int child=0;
	low[u]=dfn[u]=++num;
	for(int i=0; i<g[u].size(); i++) {
		int v=g[u][i];
		if(!dfn[v]) {
			child++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) ic[u]=true;
		} else {
			if(v!=fa&&dfn[v]<dfn[u])
				low[u]=min(low[u],dfn[v]);
		}
	}
	if(fa<0&&child==1) ic[u]=false;
	return ;
}
void dfs(int x,int color) {
	vis[x]=color;
	Fcut++;
	for(int i=0; i<g[x].size(); i++) {
		int v=g[x][i];
		if(ic[v]&&vis[v]!=color)
			Cut++,vis[v]=color;
		if(!vis[v])
			dfs(v,color);
	}
	return ;
}
signed main() {
	while(scanf("%lld",&m)!=EOF) {
		if(m==0) return 0;
		++Ans;
		Init();
		for(int i=1; i<=m; i++) {
			int x,y;
			scanf("%lld %lld",&x,&y);
			n=max(n,max(x,y));
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i=1; i<=n; i++)
			if(!dfn[i])
				tarjan(i,-1);
		for(int i=1,color=0; i<=n; i++) {
			if(!vis[i]&&!ic[i]) {
				++color;
				Fcut=Cut=0;
				dfs(i,color);
				if(Cut==0)
					Num+=2,G*=(Fcut-1)*Fcut/2;
				if(Cut==1)
					Num+=1,G*=Fcut;
			}
		}
		printf("Case %lld: %lld %lld\n",Ans,Num,G);
	}
	n=(1<<60);
	return 0;
}
