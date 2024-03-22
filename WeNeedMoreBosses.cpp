#include<bits/stdc++.h>
using namespace std;
#define M 600600
int head[M],nextt[M],ver[M],cnt=1;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int head1[M],nextt1[M],ver1[M],cnt1=1;
void addnew(int x,int y){
    ++cnt1;
    ver1[cnt1]=y;
    nextt1[cnt1]=head1[x];
    head1[x]=cnt1;
}
int dfn[M],low[M],bridge[M],v[M],c,s;
void dfsI(int x,int ine){
    s++;
    low[x]=dfn[x]=s;
    for(int i=head[x];i;i=nextt[i]){
        if(i!=ine){
            if(!dfn[ver[i]]){
                dfsI(ver[i],i^1);
                low[x]=min(low[x],low[ver[i]]);
                if(low[ver[i]]>dfn[x]) 
                    bridge[i]=bridge[i^1]=1;
            }
            else low[x]=min(low[x],dfn[ver[i]]);
        }
    }
    
}
int dcc[M];
void dfs(int x){
    dcc[x]=c;
    for(int i=head[x];i;i=nextt[i])
        if(!dcc[ver[i]]&&!bridge[i])
            dfs(ver[i]);
}
int dep[M];
void dffs(int x,int fa){
    dep[x]=dep[fa]+1;
    for(int i=head1[x];i;i=nextt1[i])
        if(ver1[i]!=fa)
            dffs(ver1[i],x);
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfsI(1,0);
    for(int i=1;i<=n;i++)
        if(dcc[i]==0)
            ++c,dfs(i);
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=nextt[j])
            if(bridge[j]){
                addnew(dcc[i],dcc[ver[j]]);
        }
    dffs(1,0);
	int x,y,m=-1;
	for(int i=1;i<=c;i++)
		if(m<dep[i])
			x=i,m=dep[i];
    
	memset(dep,0,sizeof(dep));
	dffs(x,0);
	m=-1;
	for(int i=1;i<=c;i++)
		if(m<dep[i])
			y=i,m=dep[i];
    printf("%d\n",m-1);
}