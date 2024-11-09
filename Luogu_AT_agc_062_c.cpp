#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(long long x=(l);x<=(r);x++)
#define per(x,l,r) for(long long x=(r);x>=(l);x--)
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
set<ll> ans,tmp;
ll n,k,a[101],s[101];
void out(){
    int cnt=0;
    for(auto c:ans){
        cnt++;prts(c,' ');
        if(cnt==k)break;
    }
    if(cnt<k)
        rep(i,s[n]+1,infll){
            cnt++;prts(i,' ');
            if(cnt==k)break;
        }
    exit(0);
}
int main(){
    n=read();k=read();
    rep(i,1,n)
        a[i]=read();
    sort(a+1,a+1+n);
    rep(i,1,n){
        if(a[i]>s[i-1]){
            tmp=ans;
            rep(j,s[i-1]+1,a[i]-1){
                ans.insert(j);
                if(ans.size()>=k)out();
            }
            for(auto c:tmp)
                ans.insert(c+a[i]);
        }else{
            tmp.clear();
            for(auto c:ans)
                if(c<a[i])
                    tmp.insert(c);
            if(tmp.size()>=k){
                ans=tmp;
                out();
            }
            for(auto c:ans){
                if(c>a[i]&&ans.count(c-a[i]))tmp.insert(c);
                if(c+a[i]>s[i-1])tmp.insert(c+a[i]);
            }
            ans=tmp;
        }
        s[i]=s[i-1]+a[i];
    }
    out();
}