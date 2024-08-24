#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,tag,dep,st;
};
node tr[400100];
int cnt;
void insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else {
            tr[now].son[s[i]-'a']=++cnt;
            tr[cnt].dep=tr[now].dep+1;
            now=cnt;
        }
    }
    tr[now].tag=1;
    tr[now].st=(1<<(tr[now].dep-1));
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
                tr[tr[x].son[i]].st|=tr[tr[tr[x].son[i]].fail].st;
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
    }
}
int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    getfail();
    for(int i=1;i<=m;i++){
        string t;
        cin>>t;
        int now=0;
        bool f[t.size()+10]={0};
        f[0]=1;
        int last=1;
        for(int i=0;i<t.size();i++){
            now=tr[now].son[t[i]-'a'];
            f[i+1]=((last&tr[now].st)>0?1:0);
            last<<=1;
            last+=f[i+1];
        }
        int ans=0;
        for(int i=t.size();i>=0;i--)
            if(f[i]){ans=i;break;}
        cout<<ans<<endl;
    }
}