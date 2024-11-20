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
#define psb(x) push_back(x)
#define ppb() pop_back()
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
vector<int> g[5050];
vector<int> ans,tmp;
vector<pii> eg;
int a,b;
bool v[5050];
void dfs(int x,int fa){
    ans.push_back(x);v[x]=1;
    for(int y:g[x])
        if(y!=fa&&!v[y]&&(!((x==a&&y==b)||(x==b&&y==a))))
            dfs(y,x);
}
int n,m;
int main(){
    n=read();m=read();
    rep(i,1,m){
        int x=read(),y=read();
        g[x].push_back(y);
        g[y].push_back(x);eg.push_back({x,y});
    }
    rep(i,1,n)
        sort(g[i].begin(),g[i].end());
    if(m==n){
        rep(i,1,n)
            tmp.push_back(inf);
        for(pii c:eg){
            ans.clear();msz(v);
            a=c.fi,b=c.se;
            dfs(1,0);
            if(ans.size()==n){
                int flag=0;
                rep(i,0,n-1)
                    if(ans[i]<tmp[i]){
                        flag=1;
                        break;
                    }else if(ans[i]>tmp[i])break;
                if(flag)swap(ans,tmp);
            }
        }
        for(int c:tmp)
            prts(c);
    }else{
        dfs(1,0);
        for(int c:ans)
            prts(c);
    }
    
}