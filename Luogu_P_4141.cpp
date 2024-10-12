#include<bits/stdc++.h>
using namespace std;
int dp[2020],g[2020];
int n,m;
int c[2020];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",c+i);
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=c[i];j--)
            (dp[j]+=dp[j-c[i]])%=10;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++)
            g[j]=dp[j];
        for(int j=c[i];j<=m;j++)
            (g[j]-=g[j-c[i]])%=10;
        for(int j=1;j<=m;j++)
            printf("%d",(g[j]+10)%10);
        printf("\n");
    }
}