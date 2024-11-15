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
int n,m;
pair<pii,int> rg[200200];
int t[200200];
template <int C>
struct FenwickTree{
    int c[C+1];
    FenwickTree()=default;
    int ask(int x){
        int ans=0;
        for(;x;x-=x&-x)ans+=c[x];
        return ans;
    }
    void add(int x,int d){
        for(;x<=C;x+=x&-x) c[x]+=d; 
    }
};
FenwickTree<200200> st;
int find(int l,int r){
    if(l==r)return l;
    int mid=(l+r)>>1;
    int sum=st.ask(r)-st.ask(mid);
    if(sum==(r-mid))return find(l,mid);
    else return find(mid+1,r);
}
int ans=0;int T;
int main(){
    T=read();
    while(T--){
        ms(st.c,0);ans=0;
        n=50000;m=read();
        rep(i,1,m){
            int x=read(),y=read(),z=read();
            rg[i]={{y,-x},z};
        }
        sort(rg+1,rg+1+m);
        rep(i,1,m){
            int r=rg[i].fi.fi,l=-rg[i].fi.se;
            int cnt=st.ask(r)-st.ask(l-1);
            while(cnt<rg[i].se){
                int id=find(l,r);
                cnt++,ans++;
                st.add(id,1);
            }
        }
        prts(ans,'\n');
        if(T)pc('\n');
    }
}