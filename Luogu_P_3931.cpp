#include<bits/stdc++.h>
using namespace std;
# define inf (1<<30)

int n,root,x,y,z,h[100010],v[100010],used[100010],e=-1,t,ans;
struct zx{int v,flow,pre;}ed[300010];
queue <int> q;

template <typename T> void in( T& a){
     T x=0,f=1;  char c = getchar();
    while(!isdigit(c)){if(c == '-') f=-1; c = getchar();}
    while(isdigit(c)) x = (x<<1)+(x<<3)+c-'0',c = getchar();
    a = x*f;
}

template <typename T> void maxx( T &a,const T b){a>b? 0:a=b;}
template <typename T> void minn( T &a,const T b){a<b? 0:a=b;}

inline void add( int x, int y, int z){
    ed[++e] = (zx){y,z,h[x]};
    h[x] = e;
}

inline void dfs( int x, int fa){
     bool flag = 0;
    for( int i=h[x]; i!=-1; i=ed[i].pre)
        if(fa != ed[i].v) flag = 1,dfs(ed[i].v,x),ed[i^1].flow = 0;
    if(!flag) add(x,t,inf),add(t,x,0);
}

inline bool bfs(){
    memset(v,0,sizeof(v));
    v[root] = 1;
    q.push(root);
    while(!q.empty()){
         int x = q.front();
        q.pop();
        for( int i=h[x]; i!=-1; i=ed[i].pre)
        {
             int p = ed[i].v;
            if(v[p]||!ed[i].flow) continue;
            v[p] = v[x]+1;
            q.push(p);
        }
    }
    return v[t];
}

inline int maxflow( int x, int want){
    if(!want||x == t) return want;
     int flow = 0;
    for( int i=used[x]; i!=-1; i=ed[i].pre,used[x]=i)
    {
         int p = ed[i].v;
        if(v[p] == v[x]+1&&ed[i].flow)
        {
             int f = maxflow(p,min(want,ed[i].flow));
            if(!f) continue;
            want -= f;
            flow += f;
            ed[i].flow -= f;
            ed[i^1].flow += f;
        }
    }
    return flow;
}

int main(){
    memset(h,-1,sizeof(h));
    in(n),in(root);
    t = n+1;
    for( int i=1; i<n; ++i) in(x),in(y),in(z),add(x,y,z),add(y,x,z);
    dfs(root,-1);
    while(bfs()){
        memcpy(used,h,sizeof(h));
        ans += maxflow(root,inf);
    }
    printf("%d",ans);
}