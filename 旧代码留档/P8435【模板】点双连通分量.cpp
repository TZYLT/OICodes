#include<bits/stdc++.h>
using namespace std;
#define M 6000400
int head[M],nextt[M],ver[M],cnt=1;
int dfn[M],low[M],c,id;
int st[M],h;
int n,m,a,b;
void add(int x,int y){
	cnt++;
	ver[cnt]=y;
	nextt[cnt]=head[x];
	head[x]=cnt;
}
vector<int> ans[600040];
void dfs(int x,int fa){
	//printf("[%d]",x);
	dfn[x]=low[x]=++id;
	st[++h]=x;
	int son=0;
	for(int i=head[x];i;i=nextt[i]){
		if(ver[i]!=fa){
			if(dfn[ver[i]]==0){
				++son;
				dfs(ver[i],x);
				low[x]=min(low[x],low[ver[i]]);
				if(low[ver[i]]>=dfn[x]){
					++c;
					while(st[h]!=ver[i]){
						ans[c].push_back(st[h]);
						h--;
					}
					ans[c].push_back(ver[i]);
					h--;
					ans[c].push_back(x);
				}
			}
			else low[x]=min(low[x],dfn[ver[i]]);
		}
			
	} 
	if(son==0&&fa==0)ans[++c].push_back(x);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) {
			h=0;
			dfs(i,0);
		}
	printf("%d\n",c);
	for(int i=1;i<=c;i++){
		printf("%d ",ans[i].size());
		for(int j=0;j<ans[i].size();j++)
			printf("%d ",ans[i][j]);
			putchar('\n');
	}	
}