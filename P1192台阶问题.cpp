#include<bits/stdc++.h>
using namespace std;
#define p 100003
int dp[101000];
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    dp[1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            dp[i+j]=(dp[i+j]+dp[i])%p;
    printf("%d\n",dp[n+1]);
}