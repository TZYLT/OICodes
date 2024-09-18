#include<bits/stdc++.h>
using namespace std;

int n,m,_map[1010][1010];
long long dx[1010][1010],dy[1010][1010],dz[1010][1010];
int dtx[4]={1,-1,0,0},dty[4]={0,0,1,-1};


int v[1010][1010];long long d[1010][1010];
priority_queue<pair<long long,pair<int,int> > > q;
void dijkstra(pair<int,int> s){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[s.first][s.second]=_map[s.first][s.second];
    q.push(make_pair(_map[s.first][s.second],s));
    while(q.size()){
        pair<int,int> x=q.top().second;q.pop();
        if(v[x.first][x.second])continue;
        v[x.first][x.second]=1;
        for(int i=0;i<=3;i++)
            if(x.first+dtx[i]>=1&&x.first+dtx[i]<=n&&x.second+dty[i]>=1&&x.second+dty[i]<=m){
                pair<int,int> y(x.first+dtx[i],x.second+dty[i]);
                int z=_map[y.first][y.second];
                if(d[y.first][y.second]>d[x.first][x.second]+z){
                    d[y.first][y.second]=d[x.first][x.second]+z;
                    q.push(make_pair(-d[y.first][y.second],y));
                }
            }
    }
}
int a,b,c;
int main(){
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&_map[i][j]);
    dijkstra(make_pair(1,a));
    swap(d,dx);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++)
    //         printf("%d ",dx[i][j]);
    //     printf("\n");
    // }
    dijkstra(make_pair(n,b));
    swap(d,dy);
    dijkstra(make_pair(n,c));
    swap(d,dz);
    long long ans=0x7f7f7f7f7f7f7f7f;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=min(ans,dx[i][j]+dy[i][j]+dz[i][j]-_map[i][j]*2);
    printf("%lld\n",ans);


}