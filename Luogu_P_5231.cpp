#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define gc() getchar()
#define pc(x) putchar(x)
#define ll long long
#define ull unsigned long long
#define lf double
#define Lf long double
#define pii pair<int,int>
#define fi first
#define se second
#define pf printf
constexpr int inf=0x3f3f3f3f;
constexpr ll infll=0x3f3f3f3f3f3f3f3f;
/*------Common-Fictions------*/
ll read(){
    ll x=0,f=1;char c=gc();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+(c^48);c=getchar();}
    return x*f;
}
void prt(ll x){
    if(x<0) return pc('-'),prt(-x);
    if(x>9)prt(x/10);
    pc(x%10+'0');
}
void prts(ll x,char c){prt(x);pc(c);}
/*------------------------*/
int id[100];//ESWN
struct node{
    int son[4],fail,tag;
};
node tr[10010000];
int cnt=0;
int insert(string &s){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[id[s[i]]])now=tr[now].son[id[s[i]]];
        else tr[now].son[id[s[i]]]=++cnt,now=cnt;
    }
    return now;
}
void getfail(void){
    queue<int> q;
    for(auto c:tr[0].son)
        if(c)q.push(c);
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=0;i<4;i++)  
            if(tr[x].son[i]){
                tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
                q.push(tr[x].son[i]);
            }
            else tr[x].son[i]=tr[tr[x].fail].son[i];
    }
}
int n,m;
string s,t[100100];

void get(void){
    int now=0;
    for(char c:s){
        now=tr[now].son[id[c]];
        for(int i=now;i&&!tr[i].tag;i=tr[i].fail)tr[i].tag=1;
    }
}
void finds(int i){
    int now=0,ans=0;
    rep(j,0,t[i].size()-1){
        now=tr[now].son[id[t[i][j]]];
        if(tr[now].tag)ckmax(ans,j+1);
    }
    cout<<ans<<'\n';
}
int main(){
    id['E']=0;id['S']=1;id['W']=2;id['N']=3;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    cin>>s;
    rep(i,1,m){
        cin>>t[i];
        insert(t[i]);
    }
    getfail();
    get();
    rep(i,1,m)
        finds(i); 
}   