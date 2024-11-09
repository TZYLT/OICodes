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
#define M 2000500
#define p 998244353
#define lc (q<<1)
#define rc (q<<1|1)
int l[M],r[M],maxx[M],minn[M],sum[M],sq[M];
int a[M];
void upd(int q){
    maxx[q]=max(maxx[lc],maxx[rc]);
    minn[q]=min(minn[lc],minn[rc]);
    sum[q]=(sum[lc]+sum[rc])%p;
    sq[q]=(sq[lc]+sq[rc])%p;
}
void build(int q,int li,int ri){
    //pf("[%d]",q);
    l[q]=li;r[q]=ri;
    if(li==ri){
        minn[q]=sum[q]=maxx[q]=a[li];
        sq[q]=1ll*a[li]*a[li]%p;
        return;
    }
    int mid=(li+ri)>>1;
    build(lc,li,mid);
    build(rc,mid+1,ri);
    upd(q);
}
void change(int q,int x,int d){
    if(l[q]==x&&r[q]==x){
        minn[q]=sum[q]=maxx[q]=d;
        sq[q]=1ll*d*d%p;
        return ;
    }
    int mid=(l[q]+r[q])>>1;
    if(x<=mid)change(lc,x,d);
    else change(rc,x,d);
    upd(q);
}
struct node{
    int sum,sq,maxx,minn;
    friend node operator+ (node x,node y){
        node a;
        a.sum=(x.sum+y.sum)%p;
        a.sq=(x.sq+y.sq)%p;
        a.maxx=max(x.maxx,y.maxx);
        a.minn=min(x.minn,y.minn);
        return a;
    }
};
node ask(int q,int li,int ri){
    if(li<=l[q]&&r[q]<=ri)
        return {sum[q],sq[q],maxx[q],minn[q]};
    int mid=(l[q]+r[q])>>1;
    node tp={0,0,-inf,inf};
    if(li<=mid)
        tp=tp+ask(lc,li,ri);
    if(ri>mid)
        tp=tp+ask(rc,li,ri);
    return tp;
}
int n,m;
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int sumsq(int x){
    return 1ll*x*(x+1)%p*(2*x+1)%p*qpow(6,p-2)%p;
}
int main(){
    n=read();m=read();
    rep(i,1,n)
        a[i]=read();
    build(1,1,n);
    while(m--){
        int op,l,r;
        op=read();l=read();r=read();
        if(op==1){
            change(1,l,r);
        }else{
            node ans=ask(1,l,r);
            int maxx=ans.maxx,minn=ans.minn;
            if(maxx-minn!=r-l){
                pf("yuanxing\n");
                continue;
            }
            int ck1=1ll*(maxx+minn)%p*(r-l+1)%p*qpow(2,p-2)%p;
            if(ans.sum!=ck1){
                pf("yuanxing\n");
                continue;
            }
            int ck2=(sumsq(maxx)-sumsq(minn-1)+p)%p;
            //pf("[%d,%d][%d,%d][%d,%d]\n",maxx-minn,r-l,ans.sum,ck1,ans.sq,ck2);
            if(ans.sq!=ck2){
                pf("yuanxing\n");
                continue;
            }
            pf("damushen\n");
        }
    }
}