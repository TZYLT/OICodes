#include<bits/stdc++.h>
using namespace std;
#define N 500005
struct edge{int to, val, next;} e[N];
int m, n, p, s, cnt, g[N], u[N], v[N], w[N], hd[N], bar[N], dis[N], dfn[N], low[N], stk[N], sum[N];
bool vis[N];
queue<int> q;
int ans = 0, top = 0, tot = 0, total = 0;
void add(int u, int v){
    cnt++;
    e[cnt].to = v;
    e[cnt].next = hd[u];
    hd[u] = cnt;
}
void build(int u, int v, int w){
    cnt++;
    e[cnt].to = v;
    e[cnt].val = w;
    e[cnt].next = hd[u];
    hd[u] = cnt;
}
void clear(){
    cnt = 0;
    memset(e, 0, sizeof(e));
    memset(hd, 0, sizeof(hd));
}
void readln(){
    clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u[i], &v[i]);
        add(u[i], v[i]);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    scanf("%d%d", &s, &p);
    for (int i = 1; i <= p; i++)
        scanf("%d", &bar[i]);
}
void Tarjan(int x){
    dfn[x] = low[x] = ++total;
    stk[++top] = x;
    vis[x] = true;
    for (int i = hd[x]; i; i = e[i].next)
    {
        int t = e[i].to;
        if (!dfn[t])
        {
            Tarjan(t);
            low[x] = min(low[x], low[t]);
        }
        else if (vis[t])
            low[x] = min(low[x], dfn[t]);
    }
    if (dfn[x] == low[x])
    {
        tot++;
        do
        {
            int tp = stk[top];
            sum[tot] += w[tp];
            vis[tp] = false;
            g[tp] = tot;
        } while (stk[top--] != x);
    }
}
void Spfa(int s){
    for (int i = 1; i <= tot; i++)
        dis[i] = 0;
    int gs = g[s];
    q.push(gs);
    vis[gs] = true;
    dis[gs] = sum[gs];
    while (!q.empty())
    {
        int h = q.front();
        q.pop();
        vis[h] = false;
        for (int i = hd[h]; i; i = e[i].next)
        {
            int t = e[i].to;
            if (dis[t] < dis[h] + e[i].val)
            {
                dis[t] = dis[h] + e[i].val;
                if (!vis[t])
                {
                    q.push(t);
                    vis[t] = true;
                }
            }
        }
    }
}
int main()
{
    readln();
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            Tarjan(i);
    clear();
    for (int i = 1; i <= m; i++)
        if (g[u[i]] != g[v[i]])
            build(g[u[i]], g[v[i]], sum[g[v[i]]]);
    Spfa(s);
    for (int i = 1; i <= p; i++)
        ans = max(ans, dis[g[bar[i]]]);
    printf("%d", ans);
    return 0;
}