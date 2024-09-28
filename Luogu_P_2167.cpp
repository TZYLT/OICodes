#include<bits/stdc++.h>
using namespace std;
#define mod 1000003
int dp[51][1<<15];
int t,n,m,k;
string s[16];
int main(){
    cin>>t;
    while(t--){
        memset(dp,0,sizeof dp);
        cin>>m>>k;
        for(int i=1;i<=m;i++)
            cin>>s[i];
        n=s[1].size();
        dp[0][(1<<m)-1]=1;
        for(int i=0;i<n;i++){
            for(int p='a';p<='z';p++){
                int st=0;
                for(int q=1;q<=m;q++)
                    if(s[q][i]=='?'||s[q][i]==p)
                        st|=1<<(q-1);
                for(int j=0;j<(1<<m);j++)
                    dp[i+1][st&j]=(dp[i+1][st&j]+dp[i][j])%mod;
            } 
        }   
        int ans=0;
        for(int j=0;j<(1<<m);j++)
            if(__builtin_popcount(j)==k)
                ans=(ans+dp[n][j])%mod;
        printf("%d\n",ans);


    }
}