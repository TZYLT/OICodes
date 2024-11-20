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
#define M 500200
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,a[M],b[M];
int ansl,ansr,v[M],vis[M];
int ans;
queue<int> q;
map<int,int> sa,sb;
int main(){
    n=read();
    rep(i,1,n)
        a[i]=read();
    rep(i,1,n)
        b[i]=read();
    rep(i,1,n){
        if(sa.count(a[i])){
            add(sa[a[i]],i,1);
            add(i,sa[a[i]],1);
            //pf("[%d,%d]",sa[a[i]],i);
        }else sa[a[i]]=i;
    }
    rep(i,1,n){
        if(sb.count(b[i])){
            add(sb[b[i]],i,1);
            add(i,sb[b[i]],1);
            //pf("[%d,%d]",sb[b[i]],i);
        }else if(sa.count(b[i])){
            add(sa[b[i]],i,0);
            add(i,sa[b[i]],0);
            //pf("[%d,%d]",sa[a[i]],i);
        }
        sb[b[i]]=i;
    }
    rep(i,1,n)
        if(!vis[i]){
            vis[i]=1;v[i]=1;q.push(i);
            ansl=0;ansr=0;
            while(q.size()){
                int x=q.front();q.pop();
                if(v[x])ansl++;
                else ansr++;
                for(int j=head[x];j;j=nextt[j])
                    if(!vis[ver[j]]){
                        if(edge[j]){
                            vis[ver[j]]=1;q.push(ver[j]);
                            v[ver[j]]=v[x]^1;
                        }else{
                            vis[ver[j]]=1;q.push(ver[j]);
                            v[ver[j]]=v[x];
                        }
                    }
            }
            ans+=min(ansl,ansr);
        }
    prtl(ans);
}