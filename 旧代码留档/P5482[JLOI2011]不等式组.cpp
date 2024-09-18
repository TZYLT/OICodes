//#include<bits/stdc++.h>
//using namespace std;
//#define M 100010
//int n,m,a[M],b[M],c[M],k[M],cnt,v[M],del[M],sum,mina;
//template <int C> class BinaryIndexedTrees{
//	public:
//		int data[C+1],c[C+1];
//		BinaryIndexedTrees()=default;
//		void inti(void);
//		int ask(int x);
//		void add(int x,int d);
//};
//template<int C> int BinaryIndexedTrees<C>::ask(int x){
//	int ans=0;
//	for(;x;x-=x&-x)ans+=c[x];
//	return ans;
//}
//template<int C> void BinaryIndexedTrees<C>::add(int x,int d){
//	for(;x<=C;x+=x&-x) c[x]+=d;
//}
//template<int C> void BinaryIndexedTrees<C>::inti(void){
//	for(int i=1;i<=C;i++) data[i]=c[i]=0;
//}
//
//BinaryIndexedTrees<4030000> maxx,minn;
//
//void add(int u){
//	if(a[u]==0){
//		v[u]=(b>c)?1:-1;
//		sum+=(b>c)?1:0;
//		return;
//	}
//	if(a[u]>0){
//		k[u]=(int)(c[u]-b[u])/a[u]+1;
//		if(k[u]<-1000000){
//			v[u]=1;
//			sum++;
//		} else if(k[u]>1000000) v[u]=-1;
//		else minn.add(k[u]+1500010,1);
//		return;
//	}
//	if(a[u]<0){
//		k[u]=ceil((c[u]-b[u])/a[u]);
//		if(k[u]>1000000){
//			v[u]=1;
//			sum++;
//		} else if(k[u]<-1000000) v[u]=-1;
//		else maxx.add(k[u]+1500010,1),mina++;
//	}
//}
//void erase(int u){
//	//printf("[E%d]K:%d",u,k[u]);
//	if(del[u])return;
//	del[u]=1;
//	if(v[u]==1)sum--;
//	else if(k[u]<=1000000&&k[u]>=-1000000&&v[u]==0){
//		if(a[u]>0){
//			minn.add(k[u]+1500010,-1);
//		}else if(a[u]<0){
//			maxx.add(k[u]+1500010,-1);
//			mina--;
//		}
//	}
//
//}
//
//int ask(int x){
//	int up=minn.ask(x);
//	int down=mina-maxx.ask(x-1);
//	//printf("SUM:%d UP:%d DOWN:%d\n",sum,up,down);
//	return sum+up+down;
//}
//
//int main(){
//	freopen("P5482_1.in","r",stdin);
//	freopen("P5482_1.ans","w",stdout);
//	minn.inti();
//	maxx.inti();
//	scanf("%d",&n);
//	while(n--){
//		string s;
//		cin>>s;
//		if(s[0]=='A'){
//			//printf("[A]SUM:%d CNT:%d MIA:%d\n",sum,cnt,mina);
//			cnt++;
//			cin>>a[cnt]>>b[cnt]>>c[cnt];
//			add(cnt);
//		}if(s[0]=='D'){
//			//printf("[D]SUM:%d CNT:%d MIA:%d\n",sum,cnt,mina);
//			cin>>m;
//			erase(m);
//		}else if(s[0]=='Q'){
//			//printf("[Q]SUM:%d CNT:%d MIA:%d\n",sum,cnt,mina);
//			cin>>m;
//			printf("%d\n",ask(m+1500010));
//		}
//	}
//}
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct node {
	int a,d;
} q[2*maxn];
int tail,res,d,n,ans,cnt,cet,xans,head;
double a,b,c1,num;
int c[2*maxn],C[2*maxn],sna[2*maxn];
bool st[2*maxn],vis[2*maxn],ts[2*maxn];
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int lowbit(int x) {
	return x&(-x);
}
void update1(int x,int y) {
	while(x<=2*maxn) {
		c[x]+=y;
		x+=lowbit(x);
	}
}
int sum1(int x) {
	xans=0;
	while(x) {
		xans+=c[x];
		x-=lowbit(x);
	}
	return xans;
}
void update2(int x,int y) {
	while(x<=2*maxn) {
		C[x]+=y;
		x+=lowbit(x);
	}
}
int sum2(int x) {
	xans=0;
	while(x) {
		xans+=C[x];
		x-=lowbit(x);
	}
	return xans;
}int main() {
	
		freopen("P5482_1.in","r",stdin);
		freopen("P5482_1.ans","w",stdout);
	string s;
	int i,x,k;
	n=read();
	for(i=1; i<=n; i++) {
		cin>>s;
		if(s=="Add") {
			a=read();
			b=read();
			c1=read();
			num=(c1-b)/a;
			if(a>0) {
				if(num>1e6) {
					ts[++tail]=1;
					continue;
				} else if(num<-1e6) {
					st[++tail]=1;
					res++;
					continue;
				}
			} else if(a<0) {
				if(num>1e6) {
					st[++tail]=1;
					res++;
					continue;
				} else if(num<-1e6) {
					ts[++tail]=1;
					continue;
				}
			}
			if(a>0) {
				d=(int)floor(num)+1;
				d+=maxn;
				q[++tail].a=a;
				q[tail].d=d;
				update1(d,1);
			} else if(a<0) {
				d=(int)ceil(num)-1;
				d=maxn-d;
				q[++tail].a=a;
				q[tail].d=d;
				update2(d,1);
			} else if(a==0) {
				if(c1-b<0) {
					res++;
					st[++tail]=1;
				} else if(c1-b>=0) {
					ts[++tail]=1;
				}
			}
		} else if(s=="Del") {
			x=read();
			if(vis[x]==1) continue;
			if(ts[x]==1) {
				ts[x]=0;
			} else if(st[x]==1) {
				res--;
				st[x]=0;
			} else if(q[x].a>0) {
				update1(q[x].d,-1);
			} else if(q[x].a<0) {
				update2(q[x].d,-1);
			}
			vis[x]=1;
		} else if(s=="Query") {
			k=read();
			cnt=sum1(k+maxn);
			cet=sum2(maxn-k);
			ans=cnt+cet+res;
			sna[++head]=ans;
		}
	}
	for(i=1; i<=head; i++)
		printf("%d\n",sna[i]);
	return 0;
}
