#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int dp[505][505];
int sum[505][100100];
int n,s;
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int main(){
    scanf("%d%d",&n,&s);
    for(int j=0;j<=100000;j++){
        int t=1;
        for(int i=0;i<=s;i++)
            sum[i][j+1]=(sum[i][j]+t)%p,t=1ll*t*(j+1)%p;
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        for(int j=0;j<=s;j++)
            for(int k=j;k<=s;k++)
                dp[i+1][k]=(dp[i+1][k]+1ll*dp[i][j]*(sum[k-j][r]-sum[k-j][l-1])%p)%p;
    }
    printf("%d\n",dp[n][s]);
}