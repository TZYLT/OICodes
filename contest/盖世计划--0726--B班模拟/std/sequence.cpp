#include <algorithm>
#include <cstdio>
#include <set>
using ll = long long;
inline int my_abs(int x) { return x < 0 ? -x : x; }
int arr[100005], app[100005], ans1[100005], ans2[100005];
int idx[100005], seq[100005], val[100005];
ll solve(int n, int odd, int *ans)
{
	for (int i = 0, a = odd, b = odd ^ 1; i < n; i++)
	{
		int &x = app[arr[i]] & 1 ? a : b;
		ans[x] = arr[i];
		idx[arr[i]] = i;
		x += 2;
	}
	for (int st = 0; st < 2; st++)
	{
		for (int l = st, r = st; l < n; l = r)
		{
			std::set<int> se;
			int cnt = 0;
			while (r < n && (idx[ans[l]] < l) == (idx[ans[r]] < r))
			{
				se.insert(r);
				seq[cnt++] = ans[r];
				r += 2;
			}
			std::sort(seq, seq + cnt);
			if (idx[ans[l]] < l)
			{
				for (int i = 0; i < cnt; i++)
				{
					int pos = *se.lower_bound(idx[seq[i]]);
					se.erase(pos);
					ans[pos] = seq[i];
				}
			}
			else
			{
				for (int i = cnt - 1; i >= 0; i--)
				{
					int pos = *--se.upper_bound(idx[seq[i]]);
					se.erase(pos);
					ans[pos] = seq[i];
				}
			}
		}
	}
	ll res = 0;
	for (int i = 0; i < n; i++)
		res += my_abs(idx[ans[i]] - i);
	return res;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	int n, odd = 0;
	scanf("%d", &n);
	auto print = [&] (int *ans)
	{
		for (int i = 0; i < n; i++)
			printf("%d%c", app[ans[i]], " \n"[i + 1 == n]);
	};
	auto comp = [&] (int *a, int *b)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
				return a[i] < b[i];
		}
		return false;
	};
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		odd += arr[i] & 1;
		app[i] = arr[i];
	}
	std::sort(app, app + n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = std::lower_bound(app, app + n, arr[i]) - app;
		arr[i] += val[arr[i]]++;
	}
	if (n & 1)
	{
		solve(n, odd < n - odd, ans1);
		print(ans1);
	}
	else
	{
		ll x = solve(n, 0, ans1), y = solve(n, 1, ans2);
		print(x < y || (x == y && comp(ans1, ans2)) ? ans1 : ans2);
	}
	return 0;
}

