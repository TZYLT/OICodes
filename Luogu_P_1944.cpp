#include<bits/stdc++.h>
using namespace std;
string s;
int dp[1001000],ans,id;
int main(){
    cin>>s;
    s=" "+s;
    for(int i=1;i<=s.size();i++){
        if((s[i]==']'&&s[i-dp[i-1]-1]=='[')
            ||(s[i]==')'&&s[i-dp[i-1]-1]=='('))
                dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
        if(ans<dp[i]){
            ans=dp[i];id=i;
        }
    }
    for(int i=id-ans+1;i<=id;i++)
        printf("%c",s[i]);
}