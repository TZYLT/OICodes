#include<bits/stdc++.h>
using namespace std;
#define M 400200
namespace dcc{
    int head[M],nextt[M],edge[M],ver[M],cnt=1;
    void add(int x,int y,int z){
        ++cnt;
        ver[cnt]=y;
        edge[cnt]=z;
        nextt[cnt]=head[x];
        head[x]=cnt;
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
    int ans[M];
    void dfs(int x){
        v[x]=c;
        ans[c]++;
        for(int i=head[x];i;i=nextt[i])
            if(!v[ver[i]]&&!bridge[i])dfs(ver[i]);
    }
}
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}

int _size[M],dep[M],hson[M],fa[M],top[M];
long long dis[M];
void dfsI(int x,int ffa,int w){
    int s=-1;
    _size[x]=1;fa[x]=ffa;
    dep[x]=dep[ffa]+1;
    dis[x]=dis[ffa]+w;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=ffa){
            dfsI(ver[i],x,edge[i]);
            _size[x]+=_size[ver[i]];
            if(s<_size[ver[i]])s=_size[ver[i]],hson[x]=ver[i];
        }
}
void dfsII(int x,int tp){
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
long long n,m,k;
long long ans;
int main(){
    freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        dcc::add(x,y,z);
        dcc::add(y,x,z);
    }
    dcc::dfsI(1,0);
    for(int i=1;i<=n;i++)
		if(!dcc::v[i]){
			dcc::c++;
		    dcc::dfs(i);
	    }	
    
    for(int i=1;i<=n;i++)
        for(int j=dcc::head[i];j;j=dcc::nextt[j])   
            if(dcc::bridge[j])
                add(dcc::v[i],dcc::v[dcc::ver[j]],dcc::edge[j]);

    dfsI(1,0,0);
    dfsII(1,1);
    
    for(int i=1;i<=dcc::c;i++)
        for(int j=1;j<=dcc::c;j++)
            if(i!=j){
                long long d=dis[i]+dis[j]-2*dis[lca(i,j)];
                if(d<=k)ans+=dcc::ans[i]*dcc::ans[j];
            }
    for(int i=1;i<=dcc::c;i++)
        ans+=dcc::ans[i]*(dcc::ans[i]-1);
    printf("%lld",ans/2);
    
}