#include<bits/stdc++.h>
#define maxn 1000010
using namespace std;
int n,m;
int a[maxn],ans[maxn];
int vis[maxn],tree[maxn];
struct QUE {
	int l,r,id;
} q[maxn];
inline void read(int &x) {
	char ch=getchar();
	int f=1;x=0;
	while(!isdigit(ch) && ch^'-') ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=f;
}
inline bool cmp(const QUE &a,const QUE &b) {
	return a.r<b.r;
}
inline int lowbit(int x) {
	return x&(-x);
}
void modify(int p,int v) {
	for(; p<=n; p+=lowbit(p))
		tree[p]+=v;
}
int query(int p) {
	int res=0;
	for(; p; p-=lowbit(p))
		res+=tree[p];
	return res;
}
int main() {
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]);
	read(m);
	for(int i=1; i<=m; ++i) {
		read(q[i].l);
		read(q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int pow=1;
	for(int i=1; i<=m; ++i) {
		for(int j=pow; j<=q[i].r; ++j) {
			if(vis[a[j]]) modify(vis[a[j]],-1);
			modify(j,1);
			vis[a[j]]=j;
		}
		pow=q[i].r+1;
		ans[q[i].id]=query(q[i].r)-query(q[i].l-1);
	}
	for(int i=1; i<=m; ++i) printf("%d\n",ans[i]);
	return 0;
}
