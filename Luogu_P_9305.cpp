#include <bits/stdc++.h>
#define int long long 
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int INF=1e6+5;
int k,ans[INF],pre[INF],fa_set[INF],suf[INF],n,lazy[INF],sum2[INF];
vector < pii > e[INF];
multiset <int> s[INF];
int find_set(int x) {return x==fa_set[x]?x:fa_set[x]=find_set(fa_set[x]);}
void mer(int x,int y) {
	x=find_set(x);y=find_set(y);
	if (s[x].size()>s[y].size()) swap(x,y);
	for (int i:s[x]) s[y].insert(i+lazy[x]-lazy[y]);
	s[x].clear();fa_set[x]=y;
}
void DFS(int x) {
	if (e[x].size()==0) {s[x].insert(0);sum2[x]=0;ans[x]=0;return ;}
	for (pii v:e[x]) DFS(v.fi);
	int len=e[x].size();
	for (int i=0;i<len;i++)
		pre[i]=(i-1>=0?pre[i-1]:0)+(e[x][i].se)+sum2[e[x][i].fi];
	for (int i=len-1;~i;i--)
		suf[i]=(i+1<len?suf[i+1]:0)+(e[x][i].se)+sum2[e[x][i].fi];
	
	sum2[x]=pre[len-1];
	for (int i=0;i<len;i++) {
		auto v=e[x][i];
		lazy[find_set(v.fi)]+=(i-1>=0?pre[i-1]:0)-(i+1<len?suf[i+1]:0);
		mer(x,v.fi);
	}
	int id=find_set(x);
	auto it=s[id].lower_bound(-lazy[id]),it1=it;
	if (it==s[id].end()) ans[x]=*(--it)+lazy[id];
	else if (it==s[id].begin()) ans[x]=*it+lazy[id];
	else ans[x]=min(abs(*it+lazy[id]),abs(*(--it1)+lazy[id]));
}
void solve() {
	cin>>n;
	for (int i=1;i<=n;i++) 
		vector <pii> ().swap(e[i]);
	for (int i=1;i<=n;i++) s[i].clear(),fa_set[i]=i,lazy[i]=0;
	for (int i=1;i<=n;i++) {
		int len=0;cin>>len;
		for (int j=1;j<=len;j++) {
			int x=0,y=0;
			cin>>x>>y;
			e[i].pb({x,y});
		}
	}
	DFS(1);
	if (k==2) {
		for (int i=1;i<=n;i++) cout<<abs(ans[i])<<" ";
		cout<<"\n";
	}
	else cout<<abs(ans[1])<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	int t=0;cin>>t>>k;
	while (t--) solve();
	return 0;
}