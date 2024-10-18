#include<bits/stdc++.h>
using namespace std;
#define M 200200
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int v[M],d[M];
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
int n,s,t;

int id(int x,int st){
    return x+st*n+1;
}

int main(){
    scanf("%d%d%d",&n,&s,&t);
    for(int i=1;i<=n;i++){
        add(id(i,0),id(i,1),1);
        int t,x;
        scanf("%d",&t);
        for(int j=1;j<=t;j++){
            scanf("%d",&x);
            add(id(i,j!=1),id(x,0),0);
        }
    }
    dijkstra(id(s,0));
    if(d[id(t,0)]<=150)printf("%d\n",d[id(t,0)]);
    else printf("-1\n");
}
