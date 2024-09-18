#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[2],fail,tag,find,h;
};
node tr[30100];
int cnt;
void insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'0'])now=tr[now].son[s[i]-'0'];
        else {
            tr[now].son[s[i]-'0']=++cnt;
            now=cnt;
        }
    }
    tr[now].tag=1;
}

void getfail(void){
    queue<int> q;
    for(auto c:tr[0].son)
        if(c)q.push(c);
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=0;i<=1;i++)  
            if(tr[x].son[i]){
                tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
                tr[tr[x].son[i]].tag|=tr[tr[tr[x].son[i]].fail].tag;
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
    }
}
int dfs(int x){
    int f=0;
    tr[x].find=1;tr[x].h=1;
    for(int i=0;i<=1;i++){
        if(tr[tr[x].son[i]].find==1)return 1;
        if(tr[tr[x].son[i]].tag==0&&tr[tr[x].son[i]].h==0)f|=dfs(tr[x].son[i]);
        if(f==1)return 1;
    }
    tr[x].find=0;
    return 0;
}
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        insert(s);
    }
    getfail();
    cout<<(dfs(0)?"TAK":"NIE");
}