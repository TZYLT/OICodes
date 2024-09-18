#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,tag,dfn;
};
node tr[500500];
int cnt;
int insert(string &s,int now){
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else tr[now].son[s[i]-'a']=++cnt,now=cnt;
    }
    tr[now].tag=1;
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
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
    }
}
int tot=1;
int dfs(int x){
    tr[x].dfn=++x;
    for(int i=1;i<=25;i++)
        if(tr[tr[x].son[i]].dfn==0)
            dfs(tr[x].son[i]);
}
int n,m;
int id[400400];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;string s;
        cin>>op;
        if(op==1){
            cin>>s;
            id[i]=insert(s,0);
        }else{
            int k;
            cin>>k>>s;
            id[i]=insert(s,id[k]);
        }
    }
    getfail();
    
}