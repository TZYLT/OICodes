#include<bits/stdc++.h>
using namespace std;
#define int long long
int d[303][303],n,m,q;
void upd(int x){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=min(d[i][j],d[i][x]+d[x][j]);
}
int eg[200200][3];
int v[200200];
int qs[200200][3];
int ans[200200];
signed main(){
    scanf("%lld%lld%lld",&n,&m,&q);
    int tt=q;
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&eg[i][0],&eg[i][1],&eg[i][2]);
    for(int i=1;i<=q;i++){
        scanf("%lld",&qs[i][0]);
        if(qs[i][0]==1){
            scanf("%lld",&qs[i][1]);
            v[qs[i][1]]=1;
        }else{
            scanf("%lld%lld",&qs[i][1],&qs[i][2]);
        }
    }
    memset(d,0x1f,sizeof d);
    for(int i=1;i<=m;i++){
        if(!v[i]){
            d[eg[i][0]][eg[i][1]]=min(d[eg[i][0]][eg[i][1]],eg[i][2]);
            d[eg[i][1]][eg[i][0]]=min(d[eg[i][1]][eg[i][0]],eg[i][2]);
        }
    }
    for(int i=1;i<=n;i++)
        upd(i);
    while(q){
        if(qs[q][0]==1){
            d[eg[qs[q][1]][0]][eg[qs[q][1]][1]]=min(d[eg[qs[q][1]][0]][eg[qs[q][1]][1]],eg[qs[q][1]][2]);
            d[eg[qs[q][1]][1]][eg[qs[q][1]][0]]=min(d[eg[qs[q][1]][1]][eg[qs[q][1]][0]],eg[qs[q][1]][2]);
            upd(eg[qs[q][1]][0]);
            upd(eg[qs[q][1]][1]);
            q--;
            continue;
        }
        int x=qs[q][1],y=qs[q][2];
        ans[q]=d[x][y];
        q--;
    }
    for(int i=1;i<=tt;i++)
        if(qs[i][0]==2){
            if(ans[i]<0x3f3f3f3f3f3f3f)printf("%lld\n",ans[i]);
            else printf("-1\n");
        }
}