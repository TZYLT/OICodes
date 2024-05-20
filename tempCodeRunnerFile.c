#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int N   = 2000005;
const int mod = 1000000007;
ll p[N];
int max_p[N], cnt[N];
int prime[555555], pcnt;
bool pvis[N];
int n;
void getP(int n) {
    for (int i = 2; i <= n; i++) {
        if (!pvis[i]) {
            prime[++pcnt] = i;
        }
        for (int j = 1; j <= pcnt; j++) {
            if (prime[j] * i > n)
                break;
            pvis[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
ll qpow(int a, int k) {
    ll res = 1, base = a;
    while (k) {
        if (k & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        k /= 2;
    }
    return res;
}
inline void update(int p, int k) {
    if (k > max_p[p]) {
        max_p[p] = k;
        cnt[p]   = 1;
    } else if (k == max_p[p]) {
        ++cnt[p];
    }
}
bool check(int x) {
    if (pvis[x]) {
        for (int i = 1; i <= pcnt; i++) {
            if (prime[i] * prime[i] > x) {
                break;
            }
            int k = 0;
            while (x % prime[i] == 0) {
                x /= prime[i];
                k++;
            }
            if (max_p[prime[i]] == k && cnt[prime[i]] == 1) {
                return false;
            }
        }
        if (x > 1 && max_p[x] == 1 && cnt[x] == 1)
            return false;
        return true;
    } else {
        if (max_p[x] == 1 && cnt[x] == 1)
            return false;
        return true;
    }
}
ll lcm  = 1;
int nya = 3;
bool vis[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    getP(p[n]);
    for (int i = n; i >= 1; i--) {
        if (max_p[p[i]]) {
            int val = p[i] - 1;
            for (int j = 1; j <= pcnt; j++) {
                if (prime[j] * prime[j] > val)
                    break;
                int k = 0;
                while (val % prime[j] == 0) {
                    val /= prime[j];
                    k++;
                }
                k != 0 ? update(prime[j], k) : (void)nya;
            }
            if (val > 1) {
                update(val, 1);
            }
            vis[i] = 1;
        } else {
            update(p[i], 1);
        }
    }
    for (int i = 1; i <= pcnt; i++) {
        if (max_p[prime[i]]) {
            lcm = 1ll * lcm * qpow(prime[i], max_p[prime[i]]) % mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((vis[i] && check(p[i] - 1)) || (!vis[i] && check(p[i]))) {
            lcm = (lcm + 1) % mod;
            break;
        }
    }
    cout << lcm;
}
