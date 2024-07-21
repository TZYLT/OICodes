#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a=0,fh=1;char c=getchar();
	while(c>57 or c<48){if(c=='-')fh=-1;c=getchar();}
	while(47<c and c<58){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 500005
int n,m,u,v,cnt,fa[MN],siz[MN],w[MN],top[MN],dep[MN],id[MN],ID[MN];
vector<int>edge[MN];
void dfs1(int x){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i){
			fa[edge[x][i]]=x;
			dep[edge[x][i]]=dep[x]+1;
			dfs1(edge[x][i]);
			siz[x]+=siz[edge[x][i]];
			if(siz[w[x]]<siz[edge[x][i]])w[x]=edge[x][i];
		}
}
void dfs2(int x){
	id[x]=++cnt;
	ID[cnt]=x;
	if(w[x]){top[w[x]]=top[x];dfs2(w[x]);}
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=w[x]){
			top[edge[x][i]]=edge[x][i];
			dfs2(edge[x][i]);
		}
}
int rt;
int jump(int x,int k){
	while(k>=id[x]-id[top[x]]+1&&x!=rt){
		k-=(id[x]-id[top[x]]+1);
		x=fa[top[x]];
	}
	return ID[id[x]-k];
}
#define ui unsigned int
ui S;
#define LL long long
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return S = x; 
}
int main(){
	n=read();m=read();scanf("%u",&S);
	rt=1;
	for(int i=1;i<=n;++i){
		fa[i]=read();
		if(!fa[i])rt=i;
		else edge[fa[i]].push_back(i);
	}
	dep[rt]=1;dfs1(rt);
	top[rt]=rt;dfs2(rt);
	LL ans=0;
	int lstans=0;
	for(int i=1;i<=m;++i){
		int x=(get(S)^lstans)%n+1;
		int k=(get(S)^lstans)%dep[x];
        printf("[%d:%d]",x,k);
		lstans=jump(x,k);
        printf("[%d]",lstans);
		ans^=(LL)i*lstans;
	}
	printf("%lld\n",ans);
	return 0;
}