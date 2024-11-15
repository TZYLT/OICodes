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
#define M 2001000
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,m;
multiset<int> s;
queue<int> q;
int ds[M],dt[M];
int in[M],out[M];
int id[M],pos[M],tot;
int ans=inf,ansid;
int main(){
    n=read();m=read();
    rep(i,1,m){
        int x=read(),y=read();
        in[y]++;out[x]++;
        add(x,y,0);
        add(y,x,1);
    }
    rep(i,1,n)
        if(in[i]==0)
            q.push(i);

    while(q.size()){
        int x=q.front();q.pop();
        id[x]=++tot;
        for(int i=head[x];i;i=nextt[i])
            if(!edge[i]){
                ckmax(dt[ver[i]],dt[x]+1);
                in[ver[i]]--;
                if(in[ver[i]]==0)
                    q.push(ver[i]);
            }
    }
    
    rep(i,1,n)
        if(out[i]==0)
            q.push(i);
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=nextt[i])
            if(edge[i]){
                ckmax(ds[ver[i]],ds[x]+1);
                out[ver[i]]--;
                if(out[ver[i]]==0)
                    q.push(ver[i]);
            }
    }
    rep(i,1,n)
        s.insert(ds[i]);
    rep(i,1,n)
        pos[id[i]]=i;
    rep(i,1,n){
        s.erase(s.find(ds[pos[i]]));
        for(int j=head[pos[i]];j;j=nextt[j])
            if(edge[j])
                s.erase(s.find(ds[pos[i]]+dt[ver[j]]+1));
        int na=*(--s.end());
        if(na<ans){
            ans=na;
            ansid=pos[i];
        }
        s.insert(dt[pos[i]]);
        for(int j=head[pos[i]];j;j=nextt[j])
            if(!edge[j])
                s.insert(ds[ver[j]]+dt[pos[i]]+1);    
    }
    prts(ansid);prtl(ans);
}