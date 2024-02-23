#include<bits/stdc++.h>
using namespace std;
#define M 1000500
int head[M],nextt[M],ver[M],cnt;
int dep[M],n;
void add(int x,int y){
	cnt++;
	ver[cnt]=y;
	nextt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=fa)
			dfs(ver[i],x);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	
	dfs(1,0);
	int x,y,m=-1;
	for(int i=1;i<=n;i++)
		if(m<dep[i])
			x=i,m=dep[i];
	memset(dep,0,sizeof(dep));
	dfs(x,0);
	m=-1;
	for(int i=1;i<=n;i++)
			if(m<dep[i])
				y=i,m=dep[i];
	printf("%d\n",dep[y]-1);
}
