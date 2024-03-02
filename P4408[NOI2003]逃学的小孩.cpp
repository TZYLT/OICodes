#include<bits/stdc++.h>
using namespace std;
#define M 300300
long long head[M],nextt[M],eage[M],ver[M],cnt;
void add(long long x,long long y,long long z){
    ++cnt;
    ver[cnt]=y;
    eage[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
long long dep[M];bool vis[M];
bool dfs(long long x,long long fa,long long d){
    dep[x]=dep[fa]+d;bool v=0;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)v|=dfs(ver[i],x,eage[i]);
    return vis[x]=v;
}
long long n,m;
long long dx[M],dy[M];
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        long long x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0,0);
    long long x,m=-1;
    for(int i=1;i<=n;i++)
        if(m<dep[i])m=dep[i],x=i;
    memset(dep,0,sizeof(dep));
    long long y;m=-1;
    dfs(x,0,0);
    for(int i=1;i<=n;i++)
        if(m<dep[i])m=dep[i],y=i;
    for(int i=1;i<=n;i++)
        dx[i]=dep[i];
    memset(dep,0,sizeof(dep));
    dfs(y,0,0);
    for(int i=1;i<=n;i++)
        dy[i]=dep[i];
    long long ans=-1;
    for(int i=1;i<=n;i++)
        ans=max(ans,min(dx[i],dy[i]));
    printf("%lld\n",ans+m);
}