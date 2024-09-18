#include<bits/stdc++.h>
using namespace std;
#define M 1010000
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int v[M],d[M];
int d0[M],dn[M];
priority_queue<pair<int,int> > q;
void dijkstra(int s){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[s]=0;
    q.push(make_pair(0,s));
    while(q.size()){
        int x=q.top().second;
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=head[x];i;i=nextt[i]){
            int y=ver[i],z=edge[i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)
        scanf("%d%d",&x,&y),add(x+1,y+1,1),add(y+1,x+1,1);
    dijkstra(1);
    for(int i=1;i<=n+1;i++)
        d0[i]=d[i];
    dijkstra(n+1);
    for(int i=1;i<=n+1;i++)
        dn[i]=d[i];
    dijkstra(2);
    for(int i=1;i<=n;i++)
        printf("%d\n",min(d[n+1],min(d0[2],d[i+1])+min(dn[i+1],d0[n+1])));
}