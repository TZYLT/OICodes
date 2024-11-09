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
#define M 1000100
int t,n;
int k[M],lst[M],cnt[M];
pii id[M];
vector<int> p[M];
void sol(){
    rep(i,1,n)
        cnt[i]=lst[i]=0;
    n=read();
    rep(i,1,n){
        k[i]=read();
        p[i].clear();
        rep(j,1,k[i])
            p[i].push_back(read());
        id[i]={k[i],i};
    }
    sort(id+1,id+1+n);
    rep(u,1,n){
        int i=id[u].second;
        if(!k[i])continue;
        for(auto c:p[i])
            ++cnt[lst[c]];
        for(auto c:p[i]){
            int g=lst[c];
            if(g&&cnt[g]<k[g]&&cnt[g]<k[i])
                return pf("YES\n%d %d\n",g,i),void();
        }
        for(auto c:p[i])
            --cnt[lst[c]],lst[c]=i;
    }
    pf("NO\n");
}
int main(){
    t=read();
    while(t--){
        sol();
    }
}