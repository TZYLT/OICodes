#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int cnt[7];
vector<int> G[100005];
bool c1[100005],c2[100005];
void dfs(int u)
{
	if(!G[u].size())
	{
		c1[u] = 1;c2[u] = 0;
		return;
	}
	int f = 0;int f2 = 0;
	for(int i = 0;i < G[u].size();i ++)
	{
		dfs(G[u][i]);
		f |= (c1[G[u][i]] == 0);
		f2 |= (c2[G[u][i]] == 0);
	}
	c1[u] = f;c2[u] = f2;
}
void add()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		G[i].clear(),c1[i] = c2[i] = 0;
	for(int i = 2;i <= n;i ++)
	{
		int u;scanf("%d",&u);
		G[u].push_back(i);
	}
	dfs(1);
	cnt[c1[1]*2+c2[1]] ++;
}
int qpow(int x,int y)
{
	int ans = 1;
	while(y)
	{
		if(y&1) ans = 1ll*ans*x%mod;
		x = 1ll*x*x%mod;y >>= 1;
	}
	return ans;
}
int main()
{
	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	int m;
	scanf("%d",&m);
	for(int i = 1;i <= m;i ++) add();
	int rx = 1ll*(qpow(2,cnt[0])-1)*qpow(2,m-cnt[0])%mod;
	int ry = cnt[1]?qpow(2,m-cnt[0]-1):0;
	printf("%d\n",(rx+ry)%mod);
	return 0;
}
