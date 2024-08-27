#include<bits/stdc++.h>
using namespace std;
#define p 998244353
bool a[1001000];
int dp[1001000][2][2],n;
string s;
void add(int &a,int b){a=(a+b)%p;}
int main(){
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    cin>>s;n=s.size();
    for(int i=0;i<n;i++)
        a[i]=s[i]-'0';
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            add(dp[i+1][1][0],dp[i][0][0]);
            add(dp[i+1][0][1],dp[i][0][0]);
            add(dp[i+1][1][1],dp[i][0][0]);
        }else add(dp[i+1][0][0],dp[i][0][0]);
        if(a[i]==1){
            add(dp[i+1][1][1],dp[i][0][1]);
            add(dp[i+1][1][1],dp[i][0][1]);
            add(dp[i+1][0][1],dp[i][0][1]);
        }else{
            add(dp[i+1][0][1],dp[i][0][1]);
            add(dp[i+1][0][1],dp[i][0][1]);
        }
        if(a[i]==1){
            add(dp[i+1][1][1],dp[i][1][0]);
            add(dp[i+1][1][1],dp[i][1][0]);
            add(dp[i+1][1][0],dp[i][1][0]);
        }else{
            add(dp[i+1][1][0],dp[i][1][0]);
            add(dp[i+1][1][0],dp[i][1][0]);
        }
        add(dp[i+1][1][1],3ll*dp[i][1][1]%p);
    }
    
    printf("%d\n",(((dp[n][0][0]+dp[n][0][1])%p+dp[n][1][0])%p+dp[n][1][1])%p);
}