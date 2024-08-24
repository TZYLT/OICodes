#include<bits/stdc++.h>
using namespace std;
struct node{
    int son[26],fail,tag;
};
node tr[10010];
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
}
void search(string &s,int x){
    int sum[10010]={0};
    for(int i=0;i<s.size();i++)
        sum[i]=sum[i-1]+s[i]-'0';
    for(int i=0;i<s.size();i++)
        for(int j=i;j<s.size();j++){
            if(sum[j]-sum[i-1]==x&&)
        }

}