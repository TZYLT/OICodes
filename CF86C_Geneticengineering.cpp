#include<bits/stdc++.h>
using namespace std;
int _map[256];
struct node{
    int son[4],fail,tag,dep;
};
node tr[200];
int cnt=1;
int insert(string &s){
    int now=1;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[_map[s[i]]])now=tr[now].son[_map[s[i]]];
        else tr[now].son[_map[s[i]]]=++cnt,tr[cnt].dep=tr[now].dep+1,now=cnt;
    }
    tr[now].tag=1;
    return now;
}
void getfail(void){
    queue<int> q;
    while(q.size()) q.pop();
    for(int i=0;i<=3;i++)
        if(tr[1].son[i])q.push(tr[1].son[i]),tr[tr[1].son[i]].fail=1;
        else tr[1].son[i]=1;
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=0;i<4;i++)  {
            if(tr[x].son[i]){
                tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
            tr[tr[x].son[i]].dep=max(tr[tr[x].son[i]].dep,tr[tr[tr[x].son[i]].fail].dep);
        }
    }
}
int n,m;
int f[1010][20][210];
int main(){
    _map['A']=0;
    _map['T']=1;
    _map['C']=2;
    _map['G']=3;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        insert(s);
    }
    getfail();
    f[0][0][1]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<min(19,n);j++)   
            for(int k=1;k<=cnt;k++){
                for(int nxt=0;nxt<=3;nxt++){
                        if(tr[tr[k].son[nxt]].dep>j)
                            f[i+1][0][tr[k].son[nxt]]+=f[i][j][k];
                        else f[i+1][j+1][tr[k].son[nxt]]+=f[i][j][k];
                    }
            } 
    int ans=0;
    for(int i=1;i<=cnt;i++)
        ans+=f[n][0][i];
    cout<<ans<<endl;
}