#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > G;
#define M 1010
//tree
int head1[M],nextt1[M],ver1[M],cnt1;
void add1(int x,int y){
    ++cnt1;
    ver1[cnt1]=y;
    nextt1[cnt1]=head1[x];
    head1[x]=cnt1;
}
//map
int head2[M],nextt2[M],ver2[M],cnt2;
void add2(int x,int y){
    ++cnt2;
    ver2[cnt2]=y;
    nextt2[cnt2]=head2[x];
    head2[x]=cnt2;
}

long long dp[(1<<17)][18][18];
long long g[(1<<17)];
int n,m;
void dfs(int s,int x,int fa){
    for(int i=1;i<=n;i++)if((s>>(i-1))&1)dp[s][x][i]=1;
    for(int j=head1[x];j;j=nextt1[j])
        if(ver1[j]!=fa){
            dfs(s,ver1[j],x);
            for(int i=1;i<=n;i++)
                if((s>>(i-1))&1){
                    long long tp=0;
                    for(int t=head2[i];t;t=nextt2[t])
                        if((s>>(ver2[t]-1))&1)
                            tp+=dp[s][ver1[j]][ver2[t]];
                    dp[s][x][i]*=tp;
                }
        }
    
}
int main(){
    scanf("%d%d",&n,&m);    
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        add2(x,y);
        add2(y,x);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add1(x,y);
        add1(y,x);
    }
    for(int i=0;i<(1<<n);i++)
        dfs(i,1,1);
    long long ans=0;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            if((i>>j)&1)
                g[i]+=dp[i][1][j+1];
    for(int i=0;i<(1<<n);i++)
        ans+=((n-__builtin_popcount(i))&1)?-g[i]:g[i];
    printf("%lld\n",ans);
}