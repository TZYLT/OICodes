#include<bits/stdc++.h>
using namespace std;
#define M 400200
namespace dcc {
	int head[M],nextt[M],edge[M],ver[M],cnt=1;
	void add(int x,int y,int z) {
		++cnt;
		ver[cnt]=y;
		edge[cnt]=z;
		nextt[cnt]=head[x];
		head[x]=cnt;
	}

	int dfn[M],low[M],bridge[M],v[M],c,s;
	void dfsI(int x,int ine) {
		s++;
		low[x]=dfn[x]=s;
		for(int i=head[x]; i; i=nextt[i]) {
			if(i!=ine) {
				if(!dfn[ver[i]]) {
					dfsI(ver[i],i^1);
					low[x]=min(low[x],low[ver[i]]);
					if(low[ver[i]]>dfn[x])
						bridge[i]=bridge[i^1]=1;
				} else low[x]=min(low[x],dfn[ver[i]]);
			}
		}

	}
	int ans[M];
	void dfs(int x) {
		v[x]=c;
		ans[c]++;
		for(int i=head[x]; i; i=nextt[i])
			if(!v[ver[i]]&&!bridge[i])dfs(ver[i]);
	}
}
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z) {
	++cnt;
	ver[cnt]=y;
	edge[cnt]=z;
	nextt[cnt]=head[x];
	head[x]=cnt;
}
int del[M],sum;
int _size[M],f[M];
void dfsI(int x,int fa) {
	_size[x]=1;
	for(int i=head[x]; i; i=nextt[i])
		if(ver[i]!=fa&&del[ver[i]]==0)
			dfsI(ver[i],x),_size[x]+=_size[ver[i]];
}
int hh,mf;
long long n,m,k;
long long ans;
void dfsII(int x,int fa,int s) {
	f[x]=s-_size[x];
	for(int i=head[x]; i; i=nextt[i])
		if(ver[i]!=fa&&del[ver[i]]==0)
			dfsII(ver[i],x,s),f[x]=max(f[x],_size[ver[i]]);
	if(mf>=f[x])mf=f[x],hh=x;
}
int gethh(int x) {
	dfsI(x,0);
	mf=(1<<60);
	dfsII(x,0,_size[x]);
	return hh;
}
int dis[M];
set<int> s[M];
void dfs(int rt,int x,int w,int fa) {
	dis[x]=dis[fa]+w;
	if(dis[x]<=k)s[rt].insert(dis[x]);
	for(int i=head[x]; i; i=nextt[i])
		if(del[ver[i]]!=1&&ver[i]!=fa)
			dfs(rt,ver[i],edge[i],x);
}
void soldfs(int x,int fa) {
	dis[x]=0;s[x].clear();
	for(int i=head[x]; i; i=nextt[i])
		if(del[ver[i]]!=1) {
			s[ver[i]].clear();
			dfs(ver[i],ver[i],edge[i],x);
			if(s[x].size()<s[ver[x]].size())swap(s[x],s[ver[i]]);
			
			
		}
}

int main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		dcc::add(x,y,z);
		dcc::add(y,x,z);
	}
	dcc::dfsI(1,0);
	for(int i=1; i<=n; i++)
		if(!dcc::v[i]) {
			dcc::c++;
			dcc::dfs(i);
		}

	for(int i=1; i<=n; i++)
		for(int j=dcc::head[i]; j; j=dcc::nextt[j])
			if(dcc::bridge[j])
				add(dcc::v[i],dcc::v[dcc::ver[j]],dcc::edge[j]);

}
