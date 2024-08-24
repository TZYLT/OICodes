#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],tag;
};
node tr[400200];
int cnt;
int insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else tr[now].son[s[i]-'a']=++cnt,now=cnt;
    }
    tr[now].tag=1;
    return now;
}
set<int> sol;
void dfs(int dep,int x,int op,string &s){
    if(dep>=s.size()){
        if(tr[x].tag==1)
            if(sol.count(x)==0)sol.insert(x);
        if(op==1){
            for(int i=0;i<26;i++)
                if(tr[x].son[i])
                    dfs(dep,tr[x].son[i],0,s);
        }
        //printf("E[%d,%d,%d]:%d\n",dep,x,op,sol.size());
        return;
    }
    if(op==1){
        for(int i=0;i<26;i++)
            if(tr[x].son[i])
                dfs(dep,tr[x].son[i],0,s);
        dfs(dep+1,x,0,s);
        for(int i=0;i<26;i++)
            if(tr[x].son[i])
                dfs(dep+1,tr[x].son[i],0,s);
    }
    if(tr[x].son[s[dep]-'a'])
        dfs(dep+1,tr[x].son[s[dep]-'a'],op,s);
    //printf("[%d,%d,%d]:%d\n",dep,x,op,sol.size());
}
bool find(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])
            now=tr[now].son[s[i]-'a'];
        else return 0;
    }
    return tr[now].tag;
}
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    while(m--){
        string s;
        cin>>s;
        if(find(s))cout<<-1<<endl;
        else {
            sol.clear();
            dfs(0,0,1,s);
            cout<<sol.size()<<endl;
        }
    }
}