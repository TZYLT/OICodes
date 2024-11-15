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
#define fi firsta
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
#define M 4002000
int head[M],nextt[M],ver[M],in[M],v[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,m,t;
int main(){
    t=read();
    while(t--){
        rep(i,1,cnt)
            head[i]=nextt[i]=ver[i]=0;
        rep(i,1,n*2)
            in[i]=v[i]=0;cnt=0;
        n=read();m=read();
        rep(i,1,m){
            int x=read(),y=read();
            in[x]++;in[y+n]++;
            add(x,y+n);
            add(y+n,x);
        }
        queue<int> q;
        rep(i,1,n*2)
            if(in[i]==1)
                q.push(i);
        int cnt=0;
        while(q.size()){
            int x=q.front(),y=0;q.pop();
            //prts(x);
            if(v[x]||in[x]!=1)continue;
            v[x]=1;cnt++;
            for(int i=head[x];i;i=nextt[i])
                if(!v[ver[i]]){
                    y=ver[i];
                    break;
                }
            //prtl(y);
            v[y]=1;cnt++;
            for(int i=head[y];i;i=nextt[i])
                if(!v[ver[i]]){
                    in[ver[i]]--;
                    if(in[ver[i]]==1)
                        q.push(ver[i]);
                }
        }
        if(cnt==2*n)pf("Renko\n");
        else pf("Merry\n");
    }
}