#include<bits/stdc++.h>
using namespace std;
#define p 1024523
int n,m;
int a[505],b[505];
int dp[2][505][505];
int get(){
	char c=getchar();
	for (;c!='A'&&c!='B';c=getchar());
	return c=='A';
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)a[i]=get();
	for(int i=1;i<=m;++i)b[i]=get();
	dp[0][0][0]=1;
    for(int i=1;i<=n+m;i++){
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                dp[i&1][j][k]=0;
        for(int j=max(0,i-m);j<=min(n,i);j++)
            for(int k=max(0,i-m);k<=min(n,i);k++){
                if(j&&k&&a[j]==a[k])(dp[i&1][j][k]+=dp[(i&1)^1][j-1][k-1])%=p;
                if(j&&i-k&&a[j]==b[i-k])(dp[i&1][j][k]+=dp[(i&1)^1][j-1][k])%=p;
                if(k&&i-j&&a[k]==b[i-j])(dp[i&1][j][k]+=dp[(i&1)^1][j][k-1])%=p;
                if(i-j&&i-k&&b[i-j]==b[i-k])(dp[i&1][j][k]+=dp[(i&1)^1][j][k])%=p;
            }
    }
    printf("%d\n",dp[(n+m)&1][n][n]);
}