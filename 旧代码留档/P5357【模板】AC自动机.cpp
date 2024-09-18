#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,sum,id;
};
node tr[400100];
int cnt;
int insert(string &s,int id){
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
        for(int i=0;i<=25;i++)  
            if(tr[x].son[i]){
                tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
                tr[tr[tr[x].fail].son[i]].id++;
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
    }
}
string t;
int n;
int ans[400200],sum[400200];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        sum[i]=insert(s,i);
    }
    getfail();
    cin>>t;

    int now=0;
    for(int i=0;i<t.size();i++){
        now=tr[now].son[t[i]-'a'];
        tr[now].sum++;
    }
    queue<int> q;
    for(int i=1;i<=cnt;i++)
        if(tr[i].id==0)
            q.push(i);
    while(q.size()){
        int x=q.front();q.pop();
        ans[x]=tr[x].sum;
        tr[tr[x].fail].sum+=tr[x].sum;
        tr[tr[x].fail].id--;
        if(tr[tr[x].fail].id==0)q.push(tr[x].fail);
    }

    for(int i=1;i<=n;i++)
        cout<<ans[sum[i]]<<'\n';
}