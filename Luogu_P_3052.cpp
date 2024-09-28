#include<bits/stdc++.h>
using namespace std;
int dp[1<<18];
int n,m;
int a[20];
int sum[1<<18];
bool check(int s){
    if(sum[s]>0)return sum[s]<=m;
    long long cnt=0;
    for(int i=1;i<=n;i++)
        if((s>>(i-1))&1)
            cnt+=a[i];
    sum[s]=cnt;
    return cnt<=m;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(dp,0x7f,sizeof dp);
    dp[0]=0;
    for(int i=0;i<(1<<n);i++){
        if(check(i)){dp[i]=min(dp[i],1);continue;}
        for(int j=i;j;--j&=i)
            if(check(j))
                dp[i]=min(dp[i],dp[i^j]+1);
    }
    printf("%d\n",dp[(1<<n)-1]);
}