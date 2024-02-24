#include<bits/stdc++.h>
using namespace std;
#define M 50000
int head[M],ver[M],w[M],nextt[M],tot;
int n,f[M][2],v[M];
void add(int a,int b){
	ver[++tot]=b;
	nextt[tot]=head[a];
	head[a]=tot;
}
void dfs(int x){
	f[x][0]=0;
	f[x][1]=w[x];
	for(int i=head[x];i;i=nextt[i]){
		dfs(ver[i]);
		f[x][0]+=max(f[ver[i]][0],f[ver[i]][1]);
		f[x][1]+=f[ver[i]][0];
	}
	//printf("[DEBUG]:[%d:%d,%d],")
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(y,x);
		v[x]=1;
	}
	int root;
	for(int i=1;i<=n;i++)
		if(!v[i]){
			root=i;
			break;
		}
	dfs(root);
	printf("%d\n",max(f[root][0],f[root][1]));
}