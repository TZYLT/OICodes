#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,tag;
};
node tr[20100];
int cnt;
void insert(string &s,int id){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else tr[now].son[s[i]-'a']=++cnt,now=cnt;
    }
    tr[now].tag=id;
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

int ans[200];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(114514){
        memset(tr,0,sizeof tr);
        memset(ans,0,sizeof ans);
        string t;
        string s[200];
        cnt=0;

        cin>>n;
        if(n==0)return 0;
        for(int i=1;i<=n;i++){
            cin>>s[i];
            insert(s[i],i);
        }
        getfail();
        cin>>t;
        int now=0;
        for(int i=0;i<t.size();i++){
            now=tr[now].son[t[i]-'a'];
            for(int j=now;j;j=tr[j].fail){
                ans[tr[j].tag]++;
            }
        }

        vector<pair<int,int> > as;
        for(int i=1;i<=n;i++)
            as.push_back(make_pair(ans[i],n-i));
        sort(as.begin(),as.end());
        reverse(as.begin(),as.end());
        cout<<as[0].first<<endl;
        cout<<s[n-as[0].second]<<endl;
        for(int i=1;i<as.size();i++)
            if(as[i].first!=as[i-1].first)break;
            else cout<<s[n-as[i].second]<<endl;
        
    }
}