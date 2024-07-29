#include<bits/stdc++.h>
using namespace std;
string s,t;

int nxt[100100];
void kmp(string &s){
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
int main(){
    cin>>t>>s;
    int n=t.size(),m=s.size();
    t=" "+t;
    s=" "+s;
    kmp(s);
    int f[n+10][m+10];
    memset(f,128,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t[i]==s[j]||t[i]=='?')
                f[i][j]=f[i-1][j-1];//
            if(j==m){
                f[i][m]++;
                for(int k=nxt[m];k;k=nxt[k])
                    f[i][k]=max(f[i][k],f[i][m]);
            }    
        }
        for(int j=0;j<=m;j++)
            f[i][0]=max({f[i][0],f[i][j],f[i-1][j]});
    }
        
    cout<<f[n][0]<<endl;
}