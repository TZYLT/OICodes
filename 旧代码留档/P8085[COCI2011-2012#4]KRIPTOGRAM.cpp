#include<bits/stdc++.h>
using namespace std;
#define M 1001000
int nxt[M];
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

int Hash(string &s,int p,int q){
    int t=1,h=0;
    for(int i=s.size()-1;i>=0;i--){
        h=(h+(long long)s[i]*t%q)%q;
        t=(long long)t*p%q;
    }
    return h;
}
map<pair<int,int>,int> words;
int a[M],b[M],sa,ab;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        string s;
        cin>>s;
        if(s[0]=='$')break;
        words.
    }
}