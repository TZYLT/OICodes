#include<bits/stdc++.h>
using namespace std;
#define p 10007
struct node{
    int son[3],fail,tag;
};
node tr[10100];
int cnt;
void insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'A'])now=tr[now].son[s[i]-'A'];
        else {
            tr[now].son[s[i]-'A']=++cnt;
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
        for(int i=0;i<=2;i++)  
            if(tr[x].son[i]){
                tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
                tr[tr[x].son[i]].tag+=tr[tr[tr[x].son[i]].fail].tag;
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
    }
}

int n,m;
int f[1100][400];
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
    memset(f,0x80,sizeof f);
    f[0][0]=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<=cnt;j++) 
            for(int k=0;k<=2;k++)
                f[i+1][tr[j].son[k]]=max(f[i+1][tr[j].son[k]],f[i][j]+tr[tr[j].son[k]].tag);
    
    int ans=0;
    for(int i=0;i<=cnt;i++)
        ans=max(ans,f[m][i]);
    cout<<ans<<endl;
    
            
}