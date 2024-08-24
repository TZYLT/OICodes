#include<bits/stdc++.h>
using namespace std;
#define M 100100
int head[M],nextt[M],edge[M],ver[M],cnt;
int w[M];
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,m,b;
long long v[M],d[M];
priority_queue<pair<int,int> > q;
void dijkstra(int t){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[1]=0;
    q.push(make_pair(0,1));
    while(q.size()){
        int x=q.top().second;
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=head[x];i;i=nextt[i]){
            int y=ver[i],z=edge[i];
            if(w[y]>t)continue;
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}
int search(int l,int r){
    if(l==r)return l;
    int mid=(l+r)>>1;
    dijkstra(mid);
    if(d[n]>b)return search(mid+1,r);
    else return search(l,mid);
}
int main(){
    scanf("%d%d%d",&n,&m,&b);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);add(y,x,z);
    }
    dijkstra(2e9);
    if(d[n]>b)printf("AFK\n");
    else printf("%d\n",search(w[1],1e9));
    
}