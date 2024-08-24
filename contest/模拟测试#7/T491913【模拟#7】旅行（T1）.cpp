#include<bits/stdc++.h>
using namespace std;
int n,m,q;
pair<long long,long long> dis[505][505];
int a[505];
long long inf=(1ll<<30);
int main(){
    freopen("ex_travel2.in","r",stdin);
    freopen("ex_travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j].first=dis[i][j].second=inf;
    
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    //for(int i=1;i<=n;i++)
    //    dis[i][i].first=0,dis[i][i].second=a[i]; 
    //for(int i=1;i<=n;i++)
    //    for(int j=1;j<=n;j++)
    //        dis[i][j].second=a[i];
   
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        dis[x][y].first=z;
        dis[x][y].second=max(a[x],a[y]);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][j].first*dis[i][j].second>((dis[i][k].first+dis[k][j].first)*max(dis[i][k].second,dis[k][j].second)))
                    dis[i][j].first=dis[i][k].first+dis[k][j].first,
                    dis[i][j].second=max(dis[i][k].second,dis[k][j].second);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][j].first*dis[i][j].second>((dis[i][k].first+dis[k][j].first)*max(dis[i][k].second,dis[k][j].second)))
                    dis[i][j].first=dis[i][k].first+dis[k][j].first,
                    dis[i][j].second=max(dis[i][k].second,dis[k][j].second);
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=dis[x][y].first*dis[x][y].second;
        printf("%lld\n",ans>(inf<<17)?-1:ans);
    }

}
