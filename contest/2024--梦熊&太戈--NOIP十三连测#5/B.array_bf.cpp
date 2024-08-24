#include<bits/stdc++.h>
using namespace std;
#define M 998244353
int l[505],r[505],ans=0;
int dp[505],n,maxx=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",l+i,r+i),maxx=max(maxx,r[i]);
    dp[0]=1;
    for(int i=maxx;i>=0;i--){
        for(int j=1;j<=n;j++)
            if(l[j]<=i&&i<=r[j])
                dp[j]=(dp[j]+dp[j-1])%M;
    }
    // for(int i=1;i<=n;i++)
    //     ans+=dp[i];
    printf("%d\n",dp[n]);
}