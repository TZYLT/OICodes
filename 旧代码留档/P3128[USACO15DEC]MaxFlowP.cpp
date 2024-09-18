#include<bits/stdc++.h>
using namespace std;
#define M 1000500
int head[M],nextt[M],ver[M],cnt,w[M],sum[M],ans=-1;
int _size[M],dep[M],hson[M],fa[M],top[M];
int a[M];
int n,m,r;
void add(int x,int y){
	cnt++;
	ver[cnt]=y;
	nextt[cnt]=head[x];
	head[x]=cnt;
}

void dfsI(int x,int ffa){
	int s=-1;
	_size[x]=1;fa[x]=ffa;
	dep[x]=dep[ffa]+1;
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=ffa){
			dfsI(ver[i],x);
			_size[x]+=_size[ver[i]];
			if(s<_size[ver[i]])s=_size[ver[i]],hson[x]=ver[i];
		}		
}

void dfsII(int x,int tp){
	//
	top[x]=tp;
	if(!hson[x])return;
	dfsII(hson[x],tp);
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=fa[x]&&ver[i]!=hson[x])
			dfsII(ver[i],ver[i]);
}

void dfsIII(int x,int f){
	//printf("[%d]",x);
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=f){
			dfsIII(ver[i],x);
			w[x]+=w[ver[i]];
		}
	//ans=(max(ans,w[x]));
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

int main(){
	scanf("%d",&n);
	r=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfsI(r,0);
	dfsII(r,r);
	for(int i=1;i<=n-1;i++){
		int x=a[i],y=a[i+1];
		w[x]++;
		w[y]++;
		w[lca(x,y)]--;
		w[fa[lca(x,y)]]--;
	}
	
	dfsIII(1,0);
	for(int i=2;i<=n;i++)
		w[a[i]]--;
	for(int i=1;i<=n;i++)
		printf("%d\n",w[i]);
}
