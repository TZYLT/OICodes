#include<bits/stdc++.h>
using namespace std;
#define M 250100
#define sq(x) x+n+m+20
#define li(x) x+n+10
namespace scc{
    int head[M],nextt[M],ver[M],cnt;
    void add(int x,int y){
        ++cnt;
        ver[cnt]=y;
        nextt[cnt]=head[x];
        head[x]=cnt;
    }
    int dfn[M],low[M],c,id;
    int st[M],h;
    vector<int> ans[M];
    void dfs(int x,int fa){
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
}

namespace lca{ 
    int head[M],nextt[M],ver[M],cnt;
    int d[M],w[M];
    void add(int x,int y){
        ++cnt;
        ver[cnt]=y;
        nextt[cnt]=head[x];
        head[x]=cnt;
    }
    
    int _size[M],dep[M],hson[M],fa[M],top[M],dis[M];
    void dfsI(int x,int ffa){
        int s=-1;
        _size[x]=1;fa[x]=ffa;
        dep[x]=dep[ffa]+1;
        for(int i=head[x];i;i=nextt[i])
            if(ver[i]!=ffa){
                dfsI(ver[i],x);
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


    void dfs(int x,int f,int k){
        dis[x]=k;
        w[x]=d[x]+w[f];
        for(int i=head[x];i;i=nextt[i])
            if(ver[i]!=f){
            dfs(ver[i],x,k);
        }
    }
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        scc::add(x,li(i));
        scc::add(li(i),y);
        scc::add(y,li(i));
        scc::add(li(i),x);
    }
    for(int i=1;i<=n+m+10;i++)
		if(!scc::dfn[i]) {
			scc::h=0;
			scc::dfs(i,0);
		}
    for(int i=1;i<=scc::c;i++){
        //printf("[%d]:",i);
        for(int j:scc::ans[i]){
            lca::add(j,sq(i));
            lca::add(sq(i),j);
            lca::d[sq(i)]=1;
            //printf("%d ",j);
        }
        //putchar('\n');
    }
        
    for(int i=1;i<=n+m+scc::c+40;i++)
		if(!lca::dis[i]) {
			lca::dfsI(i,0);
            lca::dfsII(i,i);
            lca::dfs(i,0,i);
		}        
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(lca::dis[li(x)]!=lca::dis[li(y)]){
            printf("0\n");
            continue;
        }
        int ans=lca::w[li(x)]+lca::w[li(y)]
                    -lca::w[lca::lca(li(x),li(y))]
                    -lca::w[lca::fa[lca::lca(li(x),li(y))]]-1;
        printf("%d\n",ans);
    }
    int x,y;
        scanf("%d%d",&x,&y);

}

