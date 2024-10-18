#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int t;
string s;
int dp[110][3030];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    dp[0][0]=1;
    for(int i=1;i<=100;i++)
        for(int j=0;j<=2600;j++)
            for(int k=0;k<=25;k++)
                if(j-k>=0)(dp[i][j]+=dp[i-1][j-k])%=p;
    while(t--){
        cin>>s;
        int sum=0,n=s.size();
        for(char c:s)
            sum+=c-'a';
        cout<<(dp[n][sum]-1+p)%p<<"\n";
    }
} 