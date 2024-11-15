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
constexpr int p=998244353;
#define int long long
template <unsigned N,unsigned M,class T>
struct Matrix{
    T d[N][M];
    unsigned n=N;
    unsigned m=M;
    
    void setClear(){
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                d[i][j]=0;
    }
    Matrix(){setClear();}
    void setIdentity(){
        setClear();
        for(unsigned i=0;i<min(n,m);i++)
            d[i][i]=1;
    }
    void operator=(const Matrix<N,M,T> &in){
        n=in.n;m=in.m;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                d[i][j]=in.d[i][j];
    }
    Matrix<N,M,T> operator+(const Matrix<N,M,T> &in){
        Matrix<N,M,T> t;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                t.d[i][j]=(d[i][j]+in.d[i][j])%p;
        return t;
    }
    Matrix<N,M,T> operator*(const T x){
        Matrix<N,M,T> t;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                t.d[i][j]=1ll*d[i][j]*x%p;
        return t;
    }
    template <unsigned P>
    Matrix<N,P,T> operator*(const Matrix<M,P,T> &in){
        Matrix<N,P,T> t;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                for(unsigned k=0;k<in.m;k++)
                    (t.d[i][k]+=1ll*d[i][j]*in.d[j][k]%p)%=p;
        return t;
    }
    void fiction(T f(T)){
    for(unsigned i=0;i<n;i++)
        for(unsigned j=0;j<m;j++)
            d[i][j]=f(d[i][j]);
    }
};
Matrix<7,7,int> E,A;
template <unsigned C,class T>
struct FenwickTree{
    T c[C+1];
    T ask(unsigned x){T ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
    void add(unsigned x,T d){for(;x<=C;x+=x&-x) c[x]+=d;}
    void init(void){for(int i=0;i<=C;i++) c[i]=0;}
};
FenwickTree<500500,ll> bit,bitw;
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int n,k;
int f[7];
int c[500500];
int sum[500500],sz;
int inv2;
int cal(int x,int y){return 1ll*(x+y)%p*(y+p-x+1)%p*inv2%p;}
signed main(){
    n=read();k=read();
    ll n2=1ll*(n-2)*(n-3)%p*qpow(2,p-2)%p;
    E.setIdentity();
    A.setClear();
    int tp=(n2+n-3)%p,invn2=qpow(n-2,p-2),invn3=invn2*qpow(n-3,p-2)%p;
    A.d[0][0]=n2;A.d[0][1]=1; A.d[0][2]=n-2;A.d[0][3]=0;  A.d[0][4]=n-2;A.d[0][5]=0;  A.d[0][6]=0;
    A.d[1][0]=1; A.d[1][1]=n2;A.d[1][2]=0;  A.d[1][3]=n-2;A.d[1][4]=0;  A.d[1][5]=n-2;A.d[1][6]=0;
    A.d[2][0]=1; A.d[2][1]=0; A.d[2][2]=tp; A.d[2][3]=1;  A.d[2][4]=0;  A.d[2][5]=1;  A.d[2][6]=n-3;
    A.d[3][0]=0; A.d[3][1]=1; A.d[3][2]=1;  A.d[3][3]=tp; A.d[3][4]=1;  A.d[3][5]=0;  A.d[3][6]=n-3;
    A.d[4][0]=1; A.d[4][1]=0; A.d[4][2]=0;  A.d[4][3]=1;  A.d[4][4]=tp; A.d[4][5]=1;  A.d[4][6]=n-3;
    A.d[5][0]=0; A.d[5][1]=1; A.d[5][2]=1;  A.d[5][3]=0;  A.d[5][4]=1;  A.d[5][5]=tp; A.d[5][6]=n-3;
    A.d[6][0]=0; A.d[6][1]=0; A.d[6][2]=1;  A.d[6][3]=1;  A.d[6][4]=1;  A.d[6][5]=1;  A.d[6][6]=(n2+2*(n-4)%p+1)%p;
    while(k){
        if(k&1)E=E*A;
        A=A*A;k>>=1;
    }
    rep(i,0,6)
        f[i]=E.d[0][i];
    rep(i,1,n)
        c[i]=read();
    int ans=0;
    inv2=qpow(2,p-2);
    rep(i,1,n){
        sum[i]=(cal(0,i-1)+cal(0,n-i))%p;
        (sz+=sum[i])%=p;
    }
    rep(i,1,n-1){
        int dt=abs(c[i]-c[i+1])%p;
        int sa=sum[c[i]];
        int sb=sum[c[i+1]];
        ans=(ans+1ll*(f[0]+f[1])%p*dt%p)%p;
        ans=(ans+1ll*(f[2]+f[3])%p*(sb-dt+p)%p*invn2%p)%p;
        ans=(ans+1ll*(f[4]+f[5])%p*(sa-dt+p)%p*invn2%p)%p;
        int tp=2ll*((dt-sa-sb)%p)%p;
        tp=(tp+p)%p;
        ans=(ans+1ll*f[6]*(sz+tp)%p*invn3%p)%p;
    }
    prtl(ans);
}
