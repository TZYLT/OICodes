#include<bits/stdc++.h>
using namespace std;
const int maxn=10007;
const int maxm=100007;
vector <int> m[maxn],G[maxn];
int N,M;
int A[maxn];
int dfn[maxn],low[maxn],T;
int stk[maxn],top;
bool ins[maxn];
int S[maxn],C;
int sum[maxn],f[maxn],in[maxn];
void dfs(int u) {
	dfn[u]=low[u]=++T;
	stk[++top]=u;
	ins[u]=true;
	for(auto v:m[u]) {
		if(dfn[v]==0) {
			dfs(v);
			low[u]=min(low[u],low[v]);
		} else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]) {
		++C;
		while(stk[top]!=u) {
			int p=stk[top--];
			ins[p]=false;
			S[p]=C;
			sum[C]+=A[p];
		}
		ins[u]=false;
		S[u]=C;
		sum[C]+=A[u];
		--top;
	}
	return ;
}
queue <int> q;
int main() {
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++)
		scanf("%d",&A[i]);
	int u,v;
	for(int i=1; i<=M; i++)
		scanf("%d%d",&u,&v),m[u].push_back(v);
	for(int i=1; i<=N; i++)
		if(!dfn[i]) dfs(i);
	for(u=1; u<=N; u++)
		for(auto v:m[u])
			if(S[u]!=S[v]) G[S[u]].push_back(S[v]),in[S[v]]++;
	for(int i=1; i<=C; i++)
		if(!in[i]) q.push(i),f[i]=sum[i];
	while(!q.empty()) {
		u=q.front();
		q.pop();
		for(auto v:G[u]) {
			f[v]=max(f[v],f[u]+sum[v]);
			--in[v];
			if(!in[v]) q.push(v);
		}
	}
	int ans=0;
	for(int i=1; i<=C; i++)
		ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
