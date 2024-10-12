#include<bits/stdc++.h>
using namespace std;
int n,m;
map<char,int> del,add;
string s;
int dp[2020][2020];
int main(){
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
        char c;int d,a;
        cin>>c>>a>>d;
        add[c]=a;
        del[c]=d;
    }
    for(char c='a';c<='z';c++)
        if(add.count(c)==0)
            add[c]=del[c]=0x3f3f3f3f;
    s=' '+s;
    memset(dp,0x1f,sizeof(dp));
    for(int i=1;i<=m;i++)
        dp[i+1][i]=dp[i][i]=0;
    for(int len=2;len<=m;len++)
        for(int l=1,r=len;r<=m;l++,r++){
            dp[l][r]=min(dp[l][r],dp[l][r-1]+min(add[s[r]],del[s[r]]));
            dp[l][r]=min(dp[l][r],dp[l+1][r]+min(add[s[l]],del[s[l]]));
            if(s[l]==s[r])dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
        }
    printf("%d\n",dp[1][m]);
}