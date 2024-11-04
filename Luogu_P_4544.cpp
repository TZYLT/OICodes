#include<bits/stdc++.h>
using namespace std;
long long dp[2][10100];
long long tp[10100];
int q[10010],h,t;
int K,E,n;
pair<int,pair<int,int> > sp[1010];
int main(){
    scanf("%d%d%d",&K,&E,&n);
    for(int i=1;i<=n;i++){
        int x,f,c;
        scanf("%d%d%d",&x,&f,&c);
        sp[i].first=x;
        sp[i].second.first=f;
        sp[i].second.second=c;
    }
    sort(sp+1,sp+1+n);
    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        int x=sp[i].first;
        int lx=sp[i-1].first;
        int f=sp[i].second.first;
        int c=sp[i].second.second;
        for(int j=0;j<=K;j++)
            tp[j]=dp[i&1^1][j]+1ll*(x-lx)*j*j-1ll*j*c;
        h=0;t=1;
        for(int j=0;j<=K;j++){
            while(h-t+1>0&&q[t]<j-f)t++;
            while(h-t+1>0&&tp[q[h]]>tp[j])h--;
            q[++h]=j; 
            dp[i&1][j]=tp[q[t]]+1ll*j*c;
        }
    }
    printf("%lld\n",dp[n&1][K]+1ll*(E-sp[n].first)*K*K);
}