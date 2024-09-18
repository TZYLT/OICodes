#include<bits/stdc++.h>
using namespace std;
#define M 200200
int dep[M],head[M],nextt[M],ver[M],tot,n;
int inv[M];
double ans=0;
void add(int x,int y){
	ver[++tot]=y;
	nextt[tot]=head[x];
	head[x]=tot;
}

void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=fa)dfs(ver[i],x);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	//dep[1]=1;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ans+=(double)1.0/dep[i];
	printf("%.8lf\n",ans);
}