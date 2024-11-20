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
bool dfs(int op,vector<int> a,vector<int> b,vector<int> c){
    //cout<<op<<' '<<a.size()<<' '<<b.size()<<' '<<c.size()<<endl;
    if(op==0){
        if(a.size()==0)return 0;
        rep(i,0,a.size()-1){
            vector<int> A=a;
            swap(A[i],A[a.size()-1]);
            int tp=A.back();
            A.pop_back();

            vector<int> C=c;
            C.push_back(tp);
            if(dfs(1,A,b,C)==0)return 1;

            rep(j,0,c.size()-1)
                if(c[j]<tp){
                    vector<int> C=c;
                    C.push_back(tp);
                    swap(C[i],C[c.size()]);

                    A.push_back(C.back());
                    C.pop_back();
                    if(dfs(1,A,b,C)==0)return 1;
                    A.pop_back();
                }
            }
    }else{
        if(b.size()==0)return 0;
        rep(i,0,b.size()-1){
            vector<int> B=b;
            swap(B[i],B[b.size()-1]);
            int tp=B.back();
            B.pop_back();

            vector<int> C=c;
            C.push_back(tp);
            if(dfs(0,a,B,C)==0)return 1;

            rep(j,0,c.size()-1)
                if(c[j]<tp){
                    vector<int> C=c;
                    C.push_back(tp);
                    swap(C[i],C[c.size()]);
                    
                    B.push_back(C.back());
                    C.pop_back();
                    if(dfs(0,a,B,C)==0)return 1;
                    B.pop_back();
                }
            }
    }
    return 0;
}
int main(){
    vector<int> a,b,c;
    int n,m,k;
    n=read();m=read();k=read();
    rep(i,1,n)
        a.push_back(read());
    rep(i,1,m)
        b.push_back(read());
    rep(i,1,k)
        c.push_back(read());
    pf(dfs(0,a,b,c)?"Takahashi":"Aoki");
}