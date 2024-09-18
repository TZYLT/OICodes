#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],tag,id;
};
node tr[300300];
int cnt;
int insert(string &s,int id){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else tr[now].son[s[i]-'a']=++cnt,now=cnt;
    }
    tr[now].tag=1;
    tr[now].id=id;
    return now;
}
int sol(int x){
    
}
string s[30030];
int n;
vector<int> ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        insert(s[i],i);
    }
    
}