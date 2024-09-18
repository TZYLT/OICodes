#include<bits/stdc++.h>
using namespace std;
#define M 1001000
#define ll long long
int head[M],nextt[M],ver[M],cnt;
pair<ll,ll> edge[M];
void add(int x,int y,ll a,ll b){
    ++cnt;
    ver[cnt]=y;
    edge[cnt].first=a;
    edge[cnt].second=b;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int v[M];
pair<ll,ll> d[M];
priority_queue<pair<pair<ll,ll>,int> > q;
int n,m,s,t;
void dijkstra(){
    for(int i=1;i<=3*n;i++)
        d[i].first=d[i].second=0x7f7f7f7f7f7f7f7f;
    memset(v,0,sizeof(v));
    d[s]=make_pair(0,0);
    q.push(make_pair(d[s],s));
    while(q.size()){
        int x=q.top().second;
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=head[x];i;i=nextt[i]){
            int y=ver[i];
            pair<ll,ll> z=edge[i];
            pair<ll,ll> p(z.first+d[x].first,z.second+d[x].second);
            if(d[y]>p){
                d[y]=p;
                q.push(make_pair(make_pair(-d[y].first,-d[y].second),y));
            }
        }
    }
}
int id(int x,int st){
    return x+st*n;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    s=id(s,0);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(id(x,1),id(y,0),z,0);
        add(id(y,1),id(x,0),z,0);
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        add(id(i,0),id(i,1),0,x);
    }
    dijkstra();
    printf("%lld\n",d[id(t,1)].second);
}