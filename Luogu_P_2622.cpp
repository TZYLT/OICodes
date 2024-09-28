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
int n,m,a[101][101];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=0;i<(1<<n);i++){
        for(int k=1;k<=m;k++){
            int st=i;
            for(int j=1;j<=n;j++)
                if(a[k][j]==1)st&=~(1<<(j-1));
                else if(a[k][j]==-1)st|=(1<<(j-1));
            add(i+1,st+1,1);
        }
    }
    dijkstra((1<<n));
    if(d[1]==0x3f3f3f3f)printf("-1\n");
    else printf("%d\n",d[1]);
}