#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
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
#define fi first
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
#define M 701000
#define int long long
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,m,k,T;
namespace dij{
	int head[M],nextt[M],edge[M],ver[M],cnt;
	void add(int x,int y,int z){
		++cnt;
		ver[cnt]=y;
		edge[cnt]=z;
		nextt[cnt]=head[x];
		head[x]=cnt;
	}
	int v[M],d[M];
	priority_queue<pair<int,int> > q;
	void dijkstra(int s){
		memset(d,0x3f,sizeof(d));
		memset(v,0,sizeof(v));
		d[s]=0;
		q.push(make_pair(0,s));
		while(q.size()){
			int x=q.top().second;
			q.pop();
			if(v[x])continue;
			v[x]=1;
			for(int i=head[x];i;i=nextt[i]){
				int y=ver[i],z=edge[i];
				if(d[y]>d[x]+z){
					d[y]=d[x]+z;
					q.push(make_pair(-d[y],y));
				}
			}
		}
	}
}

signed main(){
    T=read();
    while(T--){
        n=read();m=read();k=read();
        rep(i,1,m){
            int x=read(),y=read(),z=read();
            add(x,y,z);
        }
        vector<int> dt;
        rep(i,1,k){
            int x=read();
            dt.push_back(x);
        }
        int lim=__lg(k)+1;
        int ans=infll;
        rep(i,0,lim){
			msz(dij::edge);msz(dij::head);
			msz(dij::nextt);msz(dij::ver);
			dij::cnt=cnt;
			rep(j,1,cnt){
				dij::edge[j]=edge[j];
				dij::nextt[j]=nextt[j];
				dij::ver[j]=ver[j];
			}
			rep(j,1,n)
				dij::head[j]=head[j];
			
            rep(j,0,dt.size()-1)
                if((j>>i)&1)dij::add(n+1,dt[j],0);
                else dij::add(dt[j],n+2,0);
			dij::dijkstra(n+1);
			ckmin(ans,dij::d[n+2]);

			msz(dij::edge);msz(dij::head);
			msz(dij::nextt);msz(dij::ver);
			dij::cnt=cnt;
			rep(j,1,cnt){
				dij::edge[j]=edge[j];
				dij::nextt[j]=nextt[j];
				dij::ver[j]=ver[j];
			}
			rep(j,1,n)
				dij::head[j]=head[j];
			
            rep(j,0,dt.size()-1)
                if((j>>i)&1)dij::add(dt[j],n+2,0);
                else dij::add(n+1,dt[j],0);
			dij::dijkstra(n+1);
			ckmin(ans,dij::d[n+2]);
        }
        prtl(ans);
        rep(i,1,cnt)
            nextt[i]=ver[i]=edge[i]=0;
        rep(i,1,n)
            head[i]=0;
    }
}
