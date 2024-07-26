#include <bits/stdc++.h>
#define FileIO_(name) \
    freopen (name ".in", "r", stdin); \
    freopen (name ".ans", "w", stdout);

using namespace std;

template<typename Tp>
void chmin (Tp &x, const Tp &y) { x = min (x, y); }
template<typename Tp>
void chmax (Tp &x, const Tp &y) { x = max (x, y); }

void read () {}

template<typename Tp, typename... Args>
void read (Tp &x, Args&... rest) {
    int c = getchar (); x = 0;
    while (!isdigit (c)) c = getchar ();
    do x = (x << 1) + (x << 3) + (c & 15);
    while (isdigit (c = getchar ()));
    read (rest...);
}

template<typename Tp>
void write (Tp x) {
    static int top, wr[50];
    do wr[++top] = x % 10; while (x /= 10);
    while (top) putchar (wr[top--] | 48);
}

typedef double dbl;
typedef long long ll;
typedef long double ldb;

namespace Main {

const int maxn = 1e5 + 20;
const int maxq = 1e5 + 20;
const int maxl = 2e5 + 20;
const int maxnum = maxn + maxq;
const int sigma = 26;
int n, q, cnt, pos[maxnum];
int fa[maxl], dep[maxl], top[maxl], tr[maxl][26];
ll val[maxl], sum[maxl], offs[maxnum];
bool flag[maxl];

mt19937 rnd ((unsigned) time (nullptr));
uniform_int_distribution<int> range (1, 500);

vector<int> g[maxl];

void init () {
    flag[0] = 1;
}

int newNode (int u) {
    fa[++cnt] = u;
    dep[cnt] = dep[u] + 1;
    top[cnt] = top[u];
    if (range (rnd) == 1) {
        top[cnt] = cnt;
        flag[cnt] = 1;
        int v = cnt;
        do {
            sum[cnt] += val[v];
            g[v].emplace_back (cnt);
        } while (!flag[v = fa[v]]);
    }
    return cnt;
}

ll query (int p) {
    int u = pos[p];
    ll res = offs[p];
    while (!flag[u]) {
        res += val[u];
        u = fa[u];
    }
    while (u) {
        res += sum[u];
        u = top[fa[u]];
    }
    return res;
}

void solve () {
    read (n);
    for (int i = 1; i <= n; ++i) {
        int u = 0, c;
        while (!islower (c = getchar ()));
        do {
            c -= 'a';
            if (!tr[u][c])
                tr[u][c] = newNode (u);
            u = tr[u][c];
        } while (islower (c = getchar ()));
        pos[i] = u;
    }
    read (q);
    while (q--) {
        static int op, p, k, c;
        read (op, p);
        if (op == 3) {
            write (query (p));
            putchar (10);
        } else {
            read (k);
            int u = pos[p];
            while (dep[top[u]] > k) {
                u = fa[top[u]];
            }
            while (dep[u] > k) {
                u = fa[u];
            }
            if (op == 1) {
                read (c);
                val[u] += c;
                for (int v : g[u]) {
                    sum[v] += c;
                }
            } else {
                while (!islower (c = getchar ()));
                do {
                    c -= 'a';
                    if (!tr[u][c])
                        tr[u][c] = newNode (u);
                    u = tr[u][c];
                } while (islower (c = getchar ()));
                pos[++n] = u;
                offs[n] = -query (n);
            }
        }
    }
}

int main () {
    int t = 1; init ();
    // read (t);
    while (t--) solve ();
    return 0;
}

} // namespace Main

int main () {

    FileIO_("book3");
    return Main::main ();
}