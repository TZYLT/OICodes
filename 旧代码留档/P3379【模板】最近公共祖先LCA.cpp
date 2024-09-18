#include<bits/stdc++.h>
using namespace std;
#define M 1000500
int head[M],nextt[M],ver[M],cnt;
int _size[M],dep[M],hson[M],fa[M],top[M];
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
	//printf("[%d]",x);
	top[x]=tp;
	if(!hson[x])return;
	dfsII(hson[x],tp);
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=fa[x]&&ver[i]!=hson[x])
			dfsII(ver[i],ver[i]);
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
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfsI(r,0);
	dfsII(r,r);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
}
