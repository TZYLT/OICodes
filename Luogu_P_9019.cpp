#include<bits/stdc++.h>
using namespace std;
int dp[31][200200];
int f[31][200200];
int cntl,cntr,n,q;
string s,t;
int v[200200];
int jump(int l,int r){
    int t=0;
    for(int i=30;i>=0;i--)
        if(dp[i][l]<r)l=dp[i][l],t+=(1<<i);
    return t+1;
}
int main(){
    scanf("%d%d",&n,&q);
    cin>>s>>t;
    for(int i=1;i<=n;i++)
        v[i]=t[i-1]-'0';
    for(int i=1;i<=2*n;i++)
        if(s[i-1]=='L') f[0][cntl]=cntl+1,cntl++;
        else dp[0][++cntr]=cntl;
    cntl=cntr=0;

    for(int i=1;i<=30;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=dp[i-1][dp[i-1][j]],
            f[i][j]=dp[i-1][dp[i-1][j]];
    for(int i=1;i<=n;i++)
        v[i]+=v[i-1];
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=jump(l,r);
        int cnt=(v[l]-v[l-1])+(v[r]-v[r-1]);
        
        printf("%d %d\n",ans,cnt);
    }
}