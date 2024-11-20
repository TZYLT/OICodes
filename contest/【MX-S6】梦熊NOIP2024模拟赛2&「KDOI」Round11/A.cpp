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
vector<int> ans[200100];
set<pii> st,fr;
pair<pii,int> qs[200200];
int n,m;
signed main(){
    n=read();m=read();
    rep(i,1,m)
        fr.insert({0,i});
    rep(i,1,n){
        int x=read(),y=read();
        qs[i]={{y,x},i};
    }   
    sort(qs+1,qs+1+n);
    rep(i,1,n){
        vector<pii> tp;
        for(auto c:st){
            if(c.fi<=qs[i].fi.fi)
                tp.push_back(c);
            else break;
        }
        for(auto c:tp){
            st.erase(c);
            fr.insert({0,c.se});
        }

        pii pt;
        if(fr.size()){
            pt=*fr.begin();
            fr.erase(pt);
            pt.first=qs[i].fi.fi;
        }else{
            pt=*st.begin();
            st.erase(pt);
        }
        ans[pt.se].push_back(qs[i].se);
        st.insert({qs[i].fi.se+pt.fi,pt.se});
    }
    rep(i,1,m){
        sort(ans[i].begin(),ans[i].end());
        prts(ans[i].size());
        for(int c:ans[i])
            prts(c);
        pc('\n');
    }
}