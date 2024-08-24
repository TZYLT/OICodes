#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,maxdfn,dfn;
    vector<int> ver;
};
node tr[1000400];
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
    for(int i=1;i<=cnt;i++)
        tr[tr[i].fail].ver.push_back(i);
}

int tot=1;
void dfs(int x){
    tr[x].dfn=++tot;
    for(int c:tr[x].ver)
        if(c!=0)dfs(c);
    tr[x].maxdfn=tot;
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
int n,m;
int v[1001000],id[1000100];
FenwickTree<1001000> seg;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        id[i]=insert(s);
    }
    getfail();
    dfs(0);
    for(int i=1;i<=n;i++){
        seg.add(tr[id[i]].maxdfn+1,-1);
        seg.add(tr[id[i]].dfn,1);
        v[i]=1;
    }
    while(m--){
        char c;
        cin>>c;
        if(c=='?'){
            string t;
            cin>>t;
            int now=0;
            int ans=0;
            for(int i=0;i<t.size();i++){
                now=tr[now].son[t[i]-'a'];
                ans+=seg.ask(tr[now].dfn);
            }
            cout<<ans<<endl;
        }else if(c=='+'){
            int x;
            cin>>x;
            if(v[x]==0){
                seg.add(tr[id[x]].maxdfn+1,-1);
                seg.add(tr[id[x]].dfn,1);
                v[x]=1;
            }
        }else {
            int x;
            cin>>x;
            if(v[x]==1){
                seg.add(tr[id[x]].maxdfn+1,1);
                seg.add(tr[id[x]].dfn,-1);
                v[x]=0;
            }
        }
    }

}