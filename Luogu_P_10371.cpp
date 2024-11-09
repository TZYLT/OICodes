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
/*------------------------*/
int a[10010000];
namespace GenHelper
{
    unsigned z1, z2, z3, z4, b;
    unsigned rand_()
    {
        b = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
}
void srand_(unsigned x, int n)
{
    using namespace GenHelper;
    z1 = x;
    z2 = (~x) ^ 0x233333333U;
    z3 = x ^ 0x1234598766U;
    z4 = (~x) + 51;
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    if (!x)
        return;
    for (int i = 1; i <= n; ++i)
    {
        int j = rand_() % i + 1, k;
        k = a[i], a[i] = a[j], a[j] = k;
    }
}
int n,s;
int b[10010000],l[10001000][2];
int r[10001000][2],ans;
int nxt[10010000],pre[10010000];
int main(){
    n=read();s=read();srand_(s,n);
    nxt[0]=0;pre[0]=1;nxt[n+1]=n;pre[n+1]=n+1;
    rep(i,1,n)
        b[a[i]]=i,nxt[i]=i-1,pre[i]=i+1;
    rep(i,1,n){
        int cur=b[i];
        l[cur][0]=nxt[cur],l[cur][1]=nxt[nxt[cur]];
        r[cur][0]=pre[cur],r[cur][1]=pre[pre[cur]];
        ans+=min(r[cur][0]-cur,cur-l[cur][0]);
        nxt[pre[cur]]=nxt[cur],pre[nxt[cur]]=pre[cur];
    }
    for(int q=1,p,cur;q<=n;++q){
        p=l[q][0],cur=r[p][0]-(p-l[q][1]);
        if(cur>=q&&cur<r[q][0]) ++ans;
        p=r[q][0],cur=l[p][0]+(r[q][1]-p);
        if(cur>l[q][0]&&cur<=q) ++ans;
    }
    prt(ans);
    return 0;
}