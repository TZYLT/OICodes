#include <cstdio>
#include <vector>
constexpr int blk = 500;
int arr[200005], app[200005], mem[200005], idx[200005], edge[505][505];
std::vector<int> adj[200005], big;
bool in[200005];
int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	
	int n, q, m;
	scanf("%d%d%d", &n, &q, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", arr + i);
		if (arr[i] == arr[i - 1])
		{
			i--;
			n--;
			continue;
		}
		app[arr[i]]++;
	}
	arr[n + 1] = 0;
	for (int i = 0; i <= n; i++)
	{
		adj[arr[i]].push_back(arr[i + 1]);
		adj[arr[i + 1]].push_back(arr[i]);
	}
	for (int i = 0; i <= m; i++)
	{
		if (adj[i].size() > blk)
		{
			idx[i] = big.size();
			big.push_back(i);
		}
	}
	for (int u : big)
	{
		for (int v : adj[u])
		{
			if (adj[v].size() > blk)
				edge[idx[u]][idx[v]]++;
		}
	}
	int V = 0, E = 0;
	while (q--)
	{
		int u;
		scanf("%d", &u);
		V += (in[u] ? -1 : 1) * app[u];
		if (adj[u].size() <= blk)
		{
			for (int v : adj[u])
			{
				E += (!in[u] && in[v]) - (in[u] && in[v]);
				if (adj[v].size() > blk)
					mem[v] += in[u] ? -1 : 1;
			}
		}
		else
		{
			E += (in[u] ? -1 : 1) * mem[u];
			for (int v : big)
				E += ((!in[u] && in[v]) - (in[u] && in[v])) * edge[idx[u]][idx[v]];
		}
		printf("%d\n", V - E);
		in[u] ^= 1;
	}
	return 0;
}

