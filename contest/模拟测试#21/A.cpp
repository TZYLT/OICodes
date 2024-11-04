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
#define M 20002000
int v[M],p[M],k;
void linearSieve(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
int t,n;
vector<ll> fc;
bool check(ll x){
    if(x<2)return 0;
    if((1ll*x*x-1)%n!=0)
        return 0;
    ll tp=(1ll*x*x-1)/n;
    for(ll i=1;i<=k&&1ll*p[i]*p[i]<=tp;i++)
        if(tp%p[i]==0){
            ll sz=tp;
            while(sz%p[i]==0)sz/=p[i];
            if(sz!=1)return 0;
            else return 1;
        }
    return 1;
}

int main(){
    linearSieve(20000000);
    //v[1]=0;
    t=read();
    while(t--){
        n=read();fc.clear();
        for(int i=1;i*i<=n;i++)
            if(n%i==0){
                if(i*i!=n){
                    if(check(i-1))fc.push_back(i-1);
                    if(check(i+1))fc.push_back(i+1);
                    if(check(n/i-1))fc.push_back(n/i-1);
                    if(check(n/i+1))fc.push_back(n/i+1);
                }
                else {
                    if(check(i-1))fc.push_back(i-1);
                    if(check(i+1))fc.push_back(i+1);
                }
            }
        for(int i=1;i<=3;i++){
            if(check(1ll*i*n-1))
                fc.push_back(1ll*i*n-1);
            if(check(1ll*i*n+1))
                fc.push_back(1ll*i*n+1);
        }
        sort(fc.begin(),fc.end());
        print(unique(fc.begin(),fc.end())-fc.begin());pc('\n');
    }
}