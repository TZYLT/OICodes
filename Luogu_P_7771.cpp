#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmod(x,y) x=(x>=(y)?x-y:(x))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define msz(x) memset(x,0,sizeof(x))
#define msu(x) memset(x,0x3f,sizeof(x))
#define msl(x) memset(x,0xcf,sizeof(x))
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
/*------Common-Factions------*/
template<class A,class B> inline void ckmax(A &x,B y){x=(x>(y)?x:(y));}
template<class A,class B> inline void ckmin(A &x,B y){x=(x<(y)?x:(y));}
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
void prts(ll x){prt(x);pc(' ');}
void prts(ll x,string s){prt(x);for(auto c:s)pc(c);}
void prtl(ll x){prt(x);pc('\n');}
/*------------------------*/
int n,m;
vector<int> g[300200];
int now[300100];
int st[300100],h;
int v[300100],in[300100];
void dfs(int x){
    for(int i=now[x];i<=(int)g[x].size()-1;i=now[x]){
        now[x]=i+1;
        dfs(g[x][i]);
    }
    st[++h]=x;
}
int main(){
    n=read();m=read();
    rep(i,1,m){
        int x=read(),y=read();
        g[x].push_back(y);
        in[x]++;in[y]--;
    }
    rep(i,1,n)
        sort(g[i].begin(),g[i].end());
    int a=0,b=0,id=1;
    rep(i,1,n)
        if(in[i]==1)
            id=i,a++;
        else if(in[i]==-1)
            b++;
        else if(in[i]!=0){
            pf("No\n");
            return 0;
        }
    if(a==b&&a==0){
        dfs(1);
        per(i,1,h)
            prts(st[i]);
        return 0;
    }
    if(a==b&&a==1){
        dfs(id);
        per(i,1,h)
            prts(st[i]);
        return 0;
    }
    pf("No\n");
    return 0;
}