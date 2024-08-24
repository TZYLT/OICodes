#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,tag,dep;
};
node tr[1000100];
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
stack<char> ans;
stack<int> path;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    n=1;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    getfail();
    int now=0;path.push(now);
    for(int i=0;i<t.size();i++){
        now=tr[now].son[t[i]-'a'];
        ans.push(t[i]);path.push(now);
        if(tr[now].tag==1){
            for(int j=1;j<=tr[now].dep;j++)
                path.pop(),ans.pop();
            now=path.top();
        }
    }
    vector<char> a;
    while(ans.size()){
        a.push_back(ans.top());
        ans.pop();
    }
    for(int i=a.size()-1;i>=0;i--)cout<<a[i];
}