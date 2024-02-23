#include<bits/stdc++.h>
using namespace std;
#define M 5000200
int head[M],nextt[M],ver[M],cnt=1;
int dfn[M],low[M],bridge[M],v[M],c,s;
int n,m,a,b;
void add(int x,int y){
	cnt++;
	ver[cnt]=y;
	nextt[cnt]=head[x];
	head[x]=cnt;
}

void dfsI(int x,int ine){
	s++;
	low[x]=dfn[x]=s;
	for(int i=head[x];i;i=nextt[i]){
		if(i!=ine){
			if(!dfn[ver[i]]){
				dfsI(ver[i],i^1);
				low[x]=min(low[x],low[ver[i]]);
				if(low[ver[i]]>dfn[x]) bridge[i]=bridge[i^1]=1;
			}
		
			else low[x]=min(low[x],dfn[ver[i]]);
		}
	}
	
}
vector<int> ans[600020];
void dfs(int x){
	v[x]=1;
	ans[c].push_back(x);
	for(int i=head[x];i;i=nextt[i])
		if(!v[ver[i]]&&!bridge[i])dfs(ver[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfsI(i,0);
	
	for(int i=1;i<=n;i++)
		if(!v[i]){
			c++;
		dfs(i);
	}		
	printf("%d\n",c);
	for(int i=1;i<=c;i++){
		printf("%d ",ans[i].size());
		for(int j=0;j<ans[i].size();j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
}
