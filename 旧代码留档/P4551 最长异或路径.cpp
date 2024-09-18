#include<bits/stdc++.h>
using namespace std;
#define M 4000100
int cnt,head[M],ver[M],nextt[M],eg[M],sum[M];
void add(int x,int y,int z){
	cnt++;
	ver[cnt]=y;
	eg[cnt]=z;
	nextt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int x,int fa,int v){
	sum[x]=sum[fa]^eg[v];
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=fa)dfs(ver[i],x,i);
}

int t[M][2],tot;

void ins(int x,int v){
	for(int i=(1<<30);i;i>>=1){
		bool c=v&i;
		if(!t[x][c]) t[x][c]=++tot;
		x=t[x][c];
	}
}
int ask(int x,int v){
	int ans=0;
	for(int i=(1<<30);i;i>>=1){
		bool c=v&i;
		if(t[x][!c])ans+=i,x=t[x][!c];
		else x=t[x][c];
	}
	return ans;
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		ins(0,sum[i]);
	
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,ask(0,sum[i]));
	printf("%d\n",ans);
}

