#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail;
    int dfn,md;
    vector<int> ver;
};
node tr[200200];
int cnt;
int insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else tr[now].son[s[i]-'a']=++cnt,now=cnt;
    }
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
    for(int i=0;i<=cnt;i++) 
        tr[tr[i].fail].ver.push_back(i);
}
int tot=1;
void dfs(int x){
    tr[x].dfn=++tot;
    for(int c:tr[x].ver)
        if(c!=0)dfs(c);
    tr[x].md=tot;
}
template <int C>
struct FenwickTree{
    int c[C+1];
    FenwickTree()=default;
    int ask(int x){
        int ans=0;
        for(;x;x-=x&-x)ans+=c[x];
        return ans;
    }
    void add(int x,int d){
        for(;x<=C;x+=x&-x) c[x]+=d; 
    }
};
vector<pair<int,int> > qs[200200];
int ans[500500],id[200200];
string s[200200];
FenwickTree<200200> seg;
int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        id[i]=insert(s[i]);
    }
    getfail();
    dfs(0);
    for(int i=1;i<=m;i++){
        int l,r,k;
        cin>>l>>r>>k;
        qs[l-1].push_back(make_pair(-k,i));
        qs[r].push_back(make_pair(k,i));
    }
    
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=0;j<s[i].size();j++){
            now=tr[now].son[s[i][j]-'a'];
            seg.add(tr[now].dfn,1);
        }
        for(pair<int,int> c:qs[i]){
            ans[abs(c.second)]+=(c.first>=0?1:-1)*(seg.ask(tr[id[abs(c.first)]].md)-seg.ask(tr[id[abs(c.first)]].dfn-1));
        }
    }  
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
}