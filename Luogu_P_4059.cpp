#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[3030][3030][2][2];
int a[4][4];
int A,B;
map<char,int> k;
string s,t;
int main(){
    cin>>s>>t;
    n=s.size();m=t.size();
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d",&A,&B);
    k['A']=0;k['T']=1;k['G']=2;k['C']=3;
    memset(dp,0xcf,sizeof dp);
    dp[0][0][0][0]=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++){
            dp[i+1][j][0][1]=max(dp[i+1][j][0][1],dp[i][j][0][0]-A);
            dp[i][j+1][1][0]=max(dp[i][j+1][1][0],dp[i][j][0][0]-A);

            dp[i+1][j][0][1]=max(dp[i+1][j][0][1],dp[i][j][0][1]-B);
            dp[i][j+1][1][0]=max(dp[i][j+1][1][0],dp[i][j][0][1]-A);

            dp[i+1][j][0][1]=max(dp[i+1][j][0][1],dp[i][j][1][0]-A);
            dp[i][j+1][1][0]=max(dp[i][j+1][1][0],dp[i][j][1][0]-B);
            
            dp[i+1][j+1][0][0]=max(dp[i+1][j+1][0][0],dp[i][j][0][0]+a[k[s[i]]][k[t[j]]]);
            dp[i+1][j+1][0][0]=max(dp[i+1][j+1][0][0],dp[i][j][1][0]+a[k[s[i]]][k[t[j]]]);
            dp[i+1][j+1][0][0]=max(dp[i+1][j+1][0][0],dp[i][j][0][1]+a[k[s[i]]][k[t[j]]]);
        }
    printf("%d\n",max({dp[n][m][0][0],dp[n][m][1][0],dp[n][m][0][1]}));
}