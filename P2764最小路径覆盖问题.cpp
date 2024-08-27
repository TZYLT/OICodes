#include<bits/stdc++.h>
using namespace std;
#define M 200200
int head[M],nextt[M],edge[M],ver[M],d[M],now[M],cnt=1;
void add(int x,int y,int z){
    ++cnt;ver[cnt]=y;edge[cnt]=z;nextt[cnt]=head[x];head[x]=cnt;
    ++cnt;ver[cnt]=x;edge[cnt]=0;nextt[cnt]=head[y];head[y]=cnt;
}
int s,t;
bool bfs(){
    memset(d,0,sizeof d);
    queue<int> q;
    q.push(s);d[s]=1;now[s]=head[s];
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=nextt[i])
            if(edge[i]&&!d[ver[i]]){
                q.push(ver[i]);
                now[ver[i]]=head[ver[i]];
                d[ver[i]]=d[x]+1;
                if(ver[i]==t)return 1;
            }
    }
    return 0;
}
int getflow(int x,int flow){
    if(x==t)return flow;
    int rest=flow;
    for(int i=now[x];i&&rest;i=nextt[i]){
        now[x]=i;
        if(edge[i]&&d[ver[i]]==d[x]+1){
            int k=getflow(ver[i],min(rest,edge[i]));
            if(!k)d[ver[i]]=0;
            edge[i]-=k;edge[i^1]+=k;
            rest-=k;
        }
    }
    return flow-rest;
}
int dinic(){
    int flow,maxflow=0;
    while(bfs())
        while(flow=getflow(s,(1<<29)))
            maxflow+=flow;
    return maxflow;        
}
int n,m;
int id(int x,int st){
    return 2+x+st*n;
}
template <int C>
struct DisjointSet{
    int fa[C];
    DisjointSet<C>& init(void){
        for(int i=0;i<C;i++)
                fa[i]=i; 
            return *this;
    }
    int get(int x){
        if(x==fa[x]) return x;
        return fa[x]=get(fa[x]);
    } 
    void merge(int x,int y){
        fa[get(x)]=get(y);
    }
};
DisjointSet<10010> st;
vector<int> sa[200];
int v[200];
int main(){
    st.init();
    scanf("%d%d",&n,&m);
    s=1;t=2*n+10;
    for(int i=1;i<=n;i++)
        add(s,id(i,0),1),add(id(i,1),t,1);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        add(id(x,0),id(y,1),1);
    }
    int ans=n-dinic();
    for(int i=1;i<=n;i++)
        for(int j=head[id(i,0)];j;j=nextt[j])
            if(ver[j]!=s&&edge[j]==0)
                st.merge(i,ver[j]-id(1,1)+1);
    for(int i=1;i<=n;i++)
        sa[st.get(i)].push_back(i);
    for(int i=1;i<=n;i++)
        if(sa[i].size()){
            for(int c:sa[i])
                printf("%d ",c);
            printf("\n");
        }
    printf("%d",ans);
}