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
void print(ll x){
    if(x<0) return pc('-'),print(-x);
    if(x>9)print(x/10);
    pc(x%10+'0');
}
/*------------------------*/
int t,n,m,l,r;
int main(){
    t=read();
    while(t--){
        l=read();r=read();m=read();n=read();
        if(l>min(n,m)){
            pf("Yes\n");
            continue;
        }
        int f=0;
        for(int i=0;i<(1<<(n+m));i++)
            if(__builtin_popcount(i)==m){
                int tag=1;
                rep(j,l,r){
                    int t=(1<<(2*j))-1;
                    int k=i;
                    while(k){
                        if(__builtin_popcount(k&t)==j)
                            {tag=0;break;}
                        k>>=1;
                    }
                    if(tag==0)break;
                }
                if(tag==1){f=1;break;}
            }
        if(f==1)pf("Yes\n");
        else pf("No\n");
    }
}