#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,fa;
    int tag[26];
    int dfn,md;
    vector<int> ver;
};
node tr[100100];
int cnt;
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
int id[100100],sum;
void insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!='P'&&s[i]!='B'){
            if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
            else {
                tr[now].son[s[i]-'a']=++cnt;
                tr[now].tag[s[i]-'a']=1;
                tr[cnt].fa=now;
                now=cnt;
            }
        }
        else if(s[i]=='B')now=tr[now].fa;
        else id[++sum]=now;
    }
}
string s;
int ans[100100];
vector<pair<int,int> > qs[100100];
FenwickTree<1001000> st;
int n;
void sol(int x){
    st.add(tr[x].dfn,1);
    for(pair<int,int> c:qs[x])
        ans[c.second]=st.ask(tr[id[c.first]].md)-st.ask(tr[id[c.first]].dfn-1);
    for(int i=0;i<=25;i++)
        if(tr[x].tag[i])
            sol(tr[x].son[i]);
    st.add(tr[x].dfn,-1);
}
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin>>s;
    insert(s);
    getfail();
    dfs(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        qs[id[y]].push_back(make_pair(x,i));
    }
    sol(0);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<"\n";
}
