#include<bits/stdc++.h>
using namespace std;
#define M 110
vector <int> son[M];
int n,m;
int f[M][M],w[M][M],tag[M];
void dfs(int u){
	tag[u]=1;		
	for(int i=0;i<son[u].size();i++){
		int v=son[u][i];
		if(tag[v]==1)continue;
		tag[v]=1;dfs(v);
		for(int j=m;j>=1;j--)
			for(int k=j-1;k>=0;k--)
				f[u][j]=max(f[u][j],w[u][v]+f[v][k]+f[u][j-k-1]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		w[x][y]=z;w[y][x]=z;
		son[x].push_back(y);
		son[y].push_back(x);
	}
	dfs(1);
	printf("%d\n",f[1][m]);
}
