#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,tag;
};
node tr[2000100];
int cnt;
void insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else tr[now].son[s[i]-'a']=++cnt,now=cnt;
    }
    tr[now].tag++;
}
void getfail(void){
    queue<int> q;
    for(auto c:tr[0].son)
        if(c)q.push(c);
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=0;i<=25;i++)  
            if(tr[x].son[i]){
                tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
    }
}
string t;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    getfail();
    cin>>t;
    int now=0,ans=0;
    for(int i=0;i<=t.size();i++){
        now=tr[now].son[t[i]-'a'];
        for(int j=now;j&&tr[j].tag!=-1;j=tr[j].fail){
            ans+=tr[j].tag;
            tr[j].tag=-1;
        }
    }
    printf("%d\n",ans);
}