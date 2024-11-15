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
#define M 100100
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,a[M],f[M];
int v[M],vis[M];
queue<int> q;
int st1[M],st2[M],h1,h2;
int main(){
    n=read();
    rep(i,1,n)
        a[i]=read();
    f[n+1]=inf;
    per(i,1,n)
        f[i]=min(f[i+1],a[i]);
    rep(i,1,n)
        rep(j,i+1,n)
            if(a[i]<a[j]&&f[j+1]<a[i])
                add(i,j),add(j,i);
    
    rep(i,1,n)
        if(!vis[i]){
            vis[i]=1;v[i]=1;
            q.push(i);
            while(q.size()){
                int x=q.front();q.pop();
                for(int i=head[x];i;i=nextt[i])
                    if(vis[ver[i]]){
                        if(v[ver[i]]==v[x]){
                            prtl(0);
                            return 0;
                        }
                    }else{
                        v[ver[i]]=v[x]^1;
                        vis[ver[i]]=1;
                        q.push(ver[i]);
                    }
            }
        }
    int now=1;
    st1[++h1]=inf;st2[++h2]=inf;
    rep(i,1,n){
        if(v[i]==1){
            if(st1[h1]>a[i]){
                st1[++h1]=a[i];
                pc('a');pc(' ');
                continue;
            }
            while(st1[h1]<a[i]){
                if(st1[h1]==now){
                    h1--;now++;
                    pc('b');pc(' ');
                }else{
                    h2--;now++;
                    pc('d');pc(' ');
                }
            }
            st1[++h1]=a[i];
            pc('a');pc(' ');
        }else{
            while(st1[h1]==now){
                h1--;now++;
                pc('b');pc(' ');
            }
            if(st2[h2]>a[i]){
                st2[++h2]=a[i];
                pc('c');pc(' ');
                continue;
            }
            while(st2[h2]<a[i]){
                if(st1[h1]==now){
                    h1--;now++;
                    pc('b');pc(' ');
                }else{
                    h2--;now++;
                    pc('d');pc(' ');
                }
            }
            while(st1[h1]==now){
                h1--;now++;
                pc('b');pc(' ');
            }
            st2[++h2]=a[i];
            pc('c');pc(' ');
        }
    }
    while(now<n+1){
        if(st1[h1]==now){
            h1--;now++;
            pc('b');pc(' ');
        }else{
            h2--;now++;
            pc('d');pc(' ');
        }
    }
}