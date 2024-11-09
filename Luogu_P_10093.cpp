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
#define int long long
#define ull unsigned long long
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
#define M 200200

int n,k;
int a[M],b[M],c[M],s[M],lf[M],rt[M],lg[M];
set<int> st;

struct ST{
	int a[M];
	int s[M];
	int ms[21][M];
	void init(){
		for(int i=1;i<=n;i++)   
            s[i]=s[i-1]+a[i],ms[0][i]=a[i];
        int lim=ceil(log2((double)n));
		for(int j=1;j<=lim;j++)
			for(int i=1;i+(1<<j)-1<=n;i++){
				int l=i,r=i+(1<<(j-1))-1;
				ms[j][i]=max(ms[j-1][i],s[r]-s[l-1]+ms[j-1][i+(1<<(j-1))]);
			}
	}
	int ask(int l,int r){
		if(l>r) return 0;
		int len=__lg(r-l+1);
		return max(ms[len][l],ms[len][r-(1<<len)+1]+s[r-(1<<len)]-s[l-1]);
	}
}t1,t2;

inline void relink(int pos){
	auto it=st.insert(pos).first,ti=it;
	ti--;it++;
	int x=*ti,y=*it;
	lf[pos]=x,rt[pos]=y;
	rt[x]=pos,lf[y]=pos;
	return ;
}

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[b[i]=i]=read();
		s[i]=s[i-1]+a[i];
		t1.a[i]=t2.a[n-i+1]=a[i];
		c[i]=a[i];
	}
	if(k==0){
		int s=0,ans=-1e18;
		for(int i=1;i<=n;i++){
			s=max(0ll,s)+a[i];
			ans=max(ans,s);
		}
		prt(ans);
		return 0;
	}
	rt[0]=n+1;lf[n+1]=0;rt[n+1]=n+1;
	st.insert(0);st.insert(n+1);

	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;

	t1.init(),t2.init();
	sort(b+1,b+1+n,[](int x,int y){return a[x]>a[y];});
	int ans=-1e18;
	for(int j=1;j<=n;j++){
		int i=b[j],pos=0,sum=a[i],now=i;
		relink(i);
		c[++pos]=i,sum=a[i];
		while(rt[now]<=n&&pos<k){
            c[++pos]=rt[now];
            sum+=a[rt[now]];
            now=rt[now];
        }
		now=i;
		int lspos=pos;
		while(pos<k&&lf[now]){
            sum+=a[lf[now]];
            now=lf[now];
            pos++;
        }
		if(pos<k) continue;
		pos=lspos;
		while(now&&pos){
			int v=c[pos--];
			int ss=s[v]-s[now-1]-sum;
			ss+=max(0ll,t2.ask(n-now+2,n-lf[now]));
			ss+=max(0ll,t1.ask(v+1,rt[v]-1));
			ans=max(ans,ss);
			sum-=a[v];
			now=lf[now];
			sum+=a[now];
		}
	}
	prt(ans);

	return 0;
}