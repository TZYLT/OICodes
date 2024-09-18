#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000010, p = 998244353;
int inv[N], jc[N], Jc[N], six[N], five[N];
void init(int n, int p)
{
	inv[1] = 1, jc[0] = 1, Jc[0] = 1;
	int Inv = 166374059;
	inv[0] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = 1LL * (p - p / i) * inv[p % i] % p;
	for (int i = 1; i <= n; i++)
		jc[i] = 1LL * jc[i - 1] * inv[i] % p, Jc[i] = 1LL * Jc[i - 1] * i % p;
	six[0] = 1;
	for (int i = 1; i <= n; i++)
		six[i] = 1ll * six[i - 1] * Inv % p;
	five[0] = 1;
	for (int i = 1; i <= n; i++)
		five[i] = 1ll * five[i - 1] * 5 % p;
}
signed main()
{
	ios::sync_with_stdio(0);
	long long ans = 0, t;
	cin >> t;
	init(5000005, p);
	cout << "tou" << endl;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a = 1ll * five[n - m] * Jc[n] % p * jc[m] % p * jc[n - m] % p * six[n] % p;
		ans ^= a;
	}
	cout << ans << endl;
	return 0;
}
