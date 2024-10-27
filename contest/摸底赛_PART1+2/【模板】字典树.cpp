#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26];
    int tag;
}tr[10010000];
int cnt;
void insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++)
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else tr[now].son[s[i]-'a']=(++cnt),now=cnt;
    tr[now].tag++;
}
int t,n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(tr,0,sizeof(node)*cnt);
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            insert(s);
        }
        while(m--){
            string s;
            cin>>s;
            int now=0;
            for(int i=0;i<s.size();i++){
                now
            }
        }
    }
}
