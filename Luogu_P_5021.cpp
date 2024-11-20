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
    if(x<0)return pc('-'),prt(-x);
    if(x>9)prt(x/10);
    pc(x%10+'0');
}
void prts(ll x,char c){prt(x);pc(c);}
void prts(ll x){prt(x);pc(' ');}
void prts(ll x,string s){prt(x);for(auto c:s)pc(c);}
void prtl(ll x){prt(x);pc('\n');}
/*------------------------*/
int n,m;
int head[100100],nextt[100100],edge[100100],ver[100100],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int ans;
int dfs(int x,int fa,int lim){
    multiset<int> s;
    vector<int> ls;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            int t=dfs(ver[i],x,lim);
            if(t+edge[i]>=lim){ans++;continue;}
            s.insert(t+edge[i]);
            ls.push_back(t+edge[i]);
        }
    if(ls.size()==0)return 0;
    sort(ls.begin(),ls.end());
    for(int c:ls){
        if(s.find(c)==s.end())continue;
        if(s.size()==1)break;
        s.erase(s.find(c));
        if(s.size()){
            auto it=s.lower_bound(lim-c);
            if(it!=s.end()){
                ans++;s.erase(it);
                continue;
            }
        }
        s.insert(c);
    }
    // while(s.size()>1){
    //     auto it=s.lower_bound(lim-*s.begin());
    //     if(it==s.begin()&&s.count(*it)==1)it++;


    // }
    if(s.size())return *--s.end();
    else return 0;
}
bool ck(int lim){
    ans=0;
    int t=dfs(1,0,lim);
    if(t>=lim)ans++;
    return ans>=m;
}
int sc(int l,int r){
    if(l>r)return -114514;
    if(l==r)return l;
    if(l+1==r){
        if(ck(r))return r;
        else return l;
    }
    int mid=(l+r)>>1;
    if(ck(mid))return sc(mid,r);
    else return sc(l,mid-1);  
}
int main(){
    n=read();m=read();
    rep(i,1,n-1){
        int x=read(),y=read(),z=read();
        add(x,y,z);
        add(y,x,z);
    }
    prtl(sc(1,100000000));
}