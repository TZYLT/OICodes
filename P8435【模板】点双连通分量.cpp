#include<bits/stdc++.h>
using namespace std;
#define M 6000400
int head[M],nextt[M],ver[M],cnt=1;
int dfn[M],low[M],c,id;
int st[M],h;
int n,m,a,b,r;
void add(int x,int y){
	cnt++;
	ver[cnt]=y;
	nextt[cnt]=head[x];
	head[x]=cnt;
}
vector<int> ans;
void dfs(int x,int fa){
	//printf("[%d]",x);
	dfn[x]=low[x]=++id;
	st[++h]=x;
	int son=0;
	for(int i=head[x];i;i=nextt[i]){
			if(dfn[ver[i]]==0){
				dfs(ver[i],x);
				
				low[x]=min(low[x],low[ver[i]]);
				if(x==r)++son;
				if(low[ver[i]]>=dfn[x]&&x!=r)
					ans.push_back(x);
			}
			else low[x]=min(low[x],dfn[ver[i]]);	
	} 
	if(son>=2&&x==r)ans.push_back(x);
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
			r=i;
			dfs(i,0);
		}
	
	sort(ans.begin(),ans.end());
	int j=unique(ans.begin(),ans.end())-ans.begin();
	printf("%d\n",j);
	for(int i=0;i<j;i++)
		printf("%d ",ans[i]);	
}
