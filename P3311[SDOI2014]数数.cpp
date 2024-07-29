#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
struct node{
    int son[10],fail,tag;
};
node tr[400100];
int cnt;
void insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'0'])now=tr[now].son[s[i]-'0'];
        else {
            tr[now].son[s[i]-'0']=++cnt;
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
        for(int i=0;i<=9;i++)  
            if(tr[x].son[i]){
                tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
                tr[tr[x].son[i]].tag|=tr[tr[tr[x].son[i]].fail].tag;
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
    }
}

int n,m;
string t;
int f[1210][2000][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    cin>>m;
    n=t.size();
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        insert(s);
    }
    getfail();
    f[0][0][0]=1;
    for(int k=1;k<=9;k++)
        if(tr[tr[0].son[k]].tag==0)
            if(k<=t[0]-'0')f[1][tr[0].son[k]][!(k==(t[0]-'0'))]=1;
    for(int i=1;i<n;i++){
        for(int k=1;k<=9;k++)
            if(tr[tr[0].son[k]].tag==0)
                f[i+1][tr[0].son[k]][1]=(f[i+1][tr[0].son[k]][1]+1)%p;
        for(int j=0;j<=cnt;j++)
            for(int k=0;k<=9;k++){
                if(tr[tr[j].son[k]].tag==0){
                    f[i+1][tr[j].son[k]][1]=(f[i+1][tr[j].son[k]][1]+f[i][j][1])%p;
                    if(k<=t[i]-'0')
                        f[i+1][tr[j].son[k]][!(k==(t[i]-'0'))]=(f[i+1][tr[j].son[k]][!(k==(t[i]-'0'))]+f[i][j][0])%p;
                }
            }
    }
        
    int ans=0;
    for(int i=0;i<=cnt;i++)
        if(tr[i].tag==0)ans=((ans+f[n][i][0])%p+f[n][i][1])%p;
    cout<<((ans)%p+p)%p<<endl;
}