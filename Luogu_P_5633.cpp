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
#define int ll
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
DisjointSet<50050> st;
vector<pair<pii,pii>> eg;
vector<pair<pii,pii>> _eg;
int n,m,s,k;
int ans=0,cnt=0;
bool ck(int dx,int dy){
    cnt=0;ans=0;
    eg.clear();
    for(auto c:_eg)
        if(c.se.fi==s||c.se.se==s)
            eg.push_back({{c.fi.fi+dx,dy},c.se});
        else eg.push_back(c);
    sort(eg.begin(),eg.end());
    st.init();
    
    for(auto c:eg){
        int w=c.fi.fi;
        int x=c.se.fi,y=c.se.se;
        if(st.get(x)!=st.get(y)){
            ans+=w;
            if(x==s||y==s)cnt++;
            st.merge(x,y);
        }
    }
    //ans-=dx*cnt;
    return cnt;
}
int sc(int l,int r){
    if(l==r)return l;
    int mid=(l+r)>>1;
    int ansl=ck(mid,1),ansr=ck(mid,-1);
    if(ansl<=k&&k<=ansr)return mid;
    if(ansr<k)return sc(l,mid);
    else return sc(mid+1,r);
}
signed main(){
    n=read();m=read();s=read();k=read();
    rep(i,1,m){
        int x=read(),y=read(),w=read();
        _eg.push_back({{w,0},{x,y}});
    }
    int dx=sc(-1e5,1e5);
    int ansl=ck(dx,1);
    int ansr=ck(dx,-1);
    if(ansl<=k&&k<=ansr)prtl(ans);
    else pf("Impossible\n");
}