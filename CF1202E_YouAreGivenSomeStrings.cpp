#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,tag;
};
node tr[200100];
int cnt;
int insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else tr[now].son[s[i]-'a']=++cnt,now=cnt;
    }
    tr[now].tag+=1;
    return now;
}
void getfail(void){
    queue<int> q;
    for(auto c:tr[0].son)
        if(c)q.push(c);
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=0;i<26;i++)  
            if(tr[x].son[i]){
                tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
                tr[tr[x].son[i]].tag+=tr[tr[tr[x].son[i]].fail].tag;
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
    }
}
string s[200100],t;
int pre[200100],suf[200100];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        insert(s[i]);
    }
    getfail();
    int now=0;
    for(int i=0;i<t.size();i++){
        now=tr[now].son[t[i]-'a'];
        pre[i]=tr[now].tag;
    }

    memset(tr,0,sizeof tr);
    cnt=0;
    for(int i=1;i<=n;i++){
        reverse(s[i].begin(),s[i].end());
        insert(s[i]);
    }
    reverse(t.begin(),t.end());
    getfail();
    now=0;
    for(int i=0;i<t.size();i++){
        now=tr[now].son[t[i]-'a'];
        suf[i]=tr[now].tag;
    }
    long long ans=0;
    for(int i=0;i<t.size();i++)
        ans+=1ll*pre[i]*suf[t.size()-i-2];
        
    cout<<ans;
}