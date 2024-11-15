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
void prts(ll x,char c){prt(x);pc(c);}
/*------------------------*/
#define M 100100
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,m;
int in[M],d[M],v[M];
bool SPFA(void){
	queue<int> q;
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	memset(in,0,sizeof(v));
	q.push(1);in[1]=0;d[1]=0;v[1]=1;
	while(q.size()){
		int x=q.front();q.pop();
		v[x]=0;
		for(int i=head[x];i;i=nextt[i]){
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				if(!v[y])q.push(y),v[y]=1,in[y]=in[x]+1;
				if(in[y]>=n)return 1;
			}
		}
	}
	return 0;
}
int main(){
    n=read();m=read();
    rep(i,1,m){
        int x=read(),y=read();
        char c=gc();
        while(c!='('&&c!=')')c=gc();
        add(x,y,(c=='(')?1:-1);
    }
    int x=SPFA();
    rep(i,1,cnt)
        edge[i]*=-1;
    int y=SPFA();
    if(!(x^y))pf("Yes\n");
    else pf("No\n");

}