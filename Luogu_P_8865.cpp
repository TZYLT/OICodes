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
#define p 998244353
#define int ll
int _map[1010][1010];
int suml[1010][1010],row[1010][1010],sumr[1010][1010];
int n,m,c,f;
int t,id;
signed main(){
    t=read();id=read();
    while(t--){
        n=read();m=read();c=read();f=read();
        msz(suml);msz(_map);msz(row);msz(sumr);
        rep(i,1,n)
            rep(j,1,m){
                char c=gc();
                while(!isdigit(c))c=gc();
                _map[i][j]=c-'0';
            }
        rep(i,1,n){
            per(j,1,m)
                if(!_map[i][j])
                    suml[i][j]=suml[i][j+1]+1;
                else suml[i][j]=0;
        }
        rep(i,1,n)
            rep(j,1,m){
                if(suml[i][j])
                    suml[i][j]--;
                sumr[i][j]=suml[i][j];
            }
        rep(j,1,m)
            per(i,1,n)
                if(!_map[i][j])
                    (suml[i][j]+=suml[i+1][j])%=p;
        int ansc=0;
        rep(i,1,n)
            rep(j,1,m)
                if(!_map[i+1][j])
                    (ansc+=1ll*sumr[i][j]*suml[i+2][j]%p)%=p;
        /*---F---*/
        msz(suml);msz(sumr);
        rep(i,1,n){
            per(j,1,m)
                if(!_map[i][j])
                    suml[i][j]=suml[i][j+1]+1;
                else suml[i][j]=0;
        }
        per(i,1,n){
            rep(j,1,m)w
                if(!_map[i][j])
                    row[i][j]=row[i+1][j]+1;
                else row[i][j]=0;
        }
        rep(i,1,n)
            rep(j,1,m){
                if(suml[i][j])
                    --suml[i][j];
                if(row[i][j])
                    --row[i][j];
                sumr[i][j]=suml[i][j];
                suml[i][j]=1ll*suml[i][j]*row[i][j]%p;
            }
        rep(j,1,m)
            per(i,1,n)
                if(!_map[i][j])(suml[i][j]+=suml[i+1][j])%=p;
        int ansf=0;
        rep(i,1,n)
            rep(j,1,m)
                if(!_map[i+1][j])
                    (ansf+=1ll*sumr[i][j]*suml[i+2][j]%p)%=p;
        prts(ansc*c);prtl(ansf*f);
    }
    
}