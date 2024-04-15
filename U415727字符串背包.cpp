#include<bits/stdc++.h>
using namespace std;
int nxt[300100];
void kmp(string &s){
    memset(nxt,0,sizeof(nxt));
    nxt[1]=0;
    for(int i=2;i<=s.size();i++){
        int p=nxt[i-1];
        while(p!=0){
            if(s[p+1]==s[i])break;
            else p=nxt[p];
        }
        nxt[i]=(s[p+1]==s[i])?p+1:0;
    }
}
string s;
vector<int> sd[200200];
int ans,w[200],len[200];
int n;long long dp[200200];
int main(){
    cin>>s;
    //double st=clock();
    cin>>n;
    for(int i=1;i<=n;i++){
        string s1;
        cin>>w[i]>>s1;
        len[i]=s1.size();
        s1='0'+s1+'#'+s;
        kmp(s1);
        for(int j=len[i]+2;j<=s1.size();j++)
            if(nxt[j]==len[i])
                sd[j-len[i]-1].push_back(i);
    }   
    for(int i=1;i<=s.size();i++){
        dp[i]=dp[i-1];
        for(auto c:sd[i])
            dp[i]=max(dp[i],dp[i-len[c]]+w[c]);
    }
        
    //int ans=-1;
    //for(int i=1;i<=s.size();i++)    
    //    ans=max(ans,dp[i]);
    printf("%lld\n",dp[s.size()]);  
    //printf("%.1lf\n",clock()-st);
}