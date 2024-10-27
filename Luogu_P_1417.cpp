#include<bits/stdc++.h>
using namespace std;
struct item{
    long long a,b,c;
    friend bool operator<(item x,item y){
        return x.b*y.c>x.c*y.b;
    }
}it[110];
int t,n;
long long dp[100100];
int main(){
    scanf("%d%d",&t,&n);
    dp[0]=0;
    for(int i=1;i<=n;i++)
        scanf("%lld",&it[i].a);
    for(int i=1;i<=n;i++)
        scanf("%lld",&it[i].b);
    for(int i=1;i<=n;i++)
        scanf("%lld",&it[i].c);
    sort(it+1,it+1+n);
    for(int i=1;i<=n;i++)
        for(int j=t;j>=it[i].c;j--)
            dp[j]=max(dp[j],dp[j-it[i].c]+(it[i].a-it[i].b*j));
    long long ans=0xcfcfcfcfcfcfcfcf;
    for(int i=0;i<=t;i++)
        ans=max(ans,dp[i]);
    printf("%lld\n",ans);
}