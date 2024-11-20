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
#define M 2001000
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int sz[M];
void dfs(int x,int fa){
    sz[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs(ver[i],x);
            sz[x]+=sz[ver[i]];
        }
}
vector<int> ans;
void dp(int x,int fa){
    int flag=1,s=0;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            if(s==0)s=sz[ver[i]];
            else if(s!=sz[ver[i]]){flag=0;break;}
        }
    if(flag==1){
        if(x!=1){
            if(s==0)ans.push_back(x);
            else if(s==sz[1]-sz[x])ans.push_back(x);
        }else ans.push_back(x);
    }
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dp(ver[i],x);
        
}
int n;
int main(){
    n=read();
    rep(i,1,n-1){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    dfs(1,0);
    dp(1,0);
    sort(ans.begin(),ans.end());
    for(int c:ans)
        prts(c);
}