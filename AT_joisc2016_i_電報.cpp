#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+5;
const int inf=0x3f3f3f3f;

int n;
int nxt[N],c[N],mx[N],tmx[N],col[N];
ll ans;
bool mark[N],vis[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&nxt[i],&c[i]);
	for(int i=1;i<=n;i++)ans+=c[i];
	for(int i=1;i<=n;i++)mx[nxt[i]]=max(mx[nxt[i]],c[i]);
	for(int i=1;i<=n;i++)if(!col[i])
	{
		int u;
		for(u=i;!col[u];u=nxt[u])col[u]=i;
		if(col[u]==i)
		{
			int cnt=0;
			for(int v=u;!mark[v];v=nxt[v])mark[v]=1,cnt++;;
			if(cnt==n)return putchar('0'),putchar('\n'),0;
		}
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
			tmx[nxt[i]]=max(tmx[nxt[i]],c[i]);
	for(int i=1;i<=n;i++)ans-=mx[i];
	for(int i=1;i<=n;i++)if(mark[i]&&!vis[i])
	{
		int mn=inf;
		for(int u=i;!vis[u];u=nxt[u])vis[u]=1,mn=min(mn,mx[u]-tmx[u]);
		ans+=mn;
	}
	cout<<ans,putchar('\n');
	return 0;
}
