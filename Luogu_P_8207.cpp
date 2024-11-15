#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(l);x>=(r);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
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
template <int C>
struct DisjointSet{
    int fa[C];
    DisjointSet<C>& init(void){
        for(int i=0;i<C;i++)
                fa[i]=i; 
            return *this;
    }
    int get(int x){
        if(x==fa[x]) return x;
        return fa[x]=get(fa[x]);
    } 
    void merge(int x,int y){
        fa[get(x)]=get(y);
    }
};
DisjointSet<1001000> st;
vector<pair<ll,pair<int,int> > > eg;
int L,R;
ll ans;
int main(){
    L=read();R=read();
    rep(i,1,R){
        ll lst=-1;
        rep(j,1,R){
            ll id=1ll*j*i;
            if(id>R)break;
            if(id<=R&&id>=L){
                if(lst==-1)lst=id;
                else eg.push_back({lst*id/__gcd(lst,id),{lst,id}});
            }
        }
    }
    st.init();
    sort(eg.begin(),eg.end());
    for(auto c:eg){
        int x=c.se.fi,y=c.se.se;
        if(st.get(x)!=st.get(y)){
            st.merge(x,y);
            ans+=c.fi;
        }
    }
    prtl(ans);
}