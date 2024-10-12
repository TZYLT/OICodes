#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5050,K = 2e7 + 1;
const int mod = 998244353;
int n,m;
long long c1[K],c2[K];
struct node
{
    int v,l,r;
} a[N];
void ckk（
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].v >> a[i].l >> a[i].r;
        //cin >> a[i].v >> a[i].l >> a[i].r;
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            long long shouxiang = (a[j].v * a[i].v) % mod;
            long long cha = shouxiang;
            int lqi = a[i].l + a[j].l;
            int len = min(a[i].r - a[i].l - 1,a[j].r - a[j].l - 1);
            int rqi = lqi + len;
            long long now = shouxiang;
            c1[lqi] = (c1[lqi] + now) % mod;
            now = cha - shouxiang;
            c1[lqi] = (c1[lqi] + now) % mod; 
            now = (-shouxiang - ((len + 1) * cha % mod))%mod;
            c1[rqi + 1] = (c1[rqi + 1] + now) % mod;
            now = (shouxiang + (len * cha % mod)) % mod;
            c1[rqi + 2] = (c1[rqi + 2] + now) % mod;

            int rmo = a[i].r + a[j].r;
            int lmo = rmo - len;
            now = (len + 2) * shouxiang % mod;
            c2[rqi + 1] = (c2[rqi + 1] + now + mod) % mod;
            now = (len + 2) * shouxiang % mod;
            c2[lmo] = (c2[lmo] - now + mod) % mod;
    
            cha = -shouxiang;
            shouxiang = ((len + 1) * shouxiang) % mod;
            now = (shouxiang + mod)%mod;
            c1[lmo] = (c1[lmo] + now + mod) % mod;
            now = (cha - shouxiang + mod) % mod;
            c1[lmo + 1] = (c1[lmo + 1] + now + mod) % mod;
            now = (-shouxiang - ((len + 1) * cha % mod) + mod) % mod;
            c1[rmo + 1] = (c1[rmo + 1] + now + mod) % mod;
            now = (shouxiang + (len * cha % mod) + mod) % mod;
            c1[rmo + 2] = (c1[rmo + 2] + now + mod) % mod;
        }
    }
    for(int i = 1;i <= 2e7;i++)
    {
        c1[i] = (c1[i] + c1[i - 1] + mod) % mod;
    }
    for(int i = 1;i <= 2e7;i++)
    {
        c1[i] = (c1[i] + c1[i - 1] + mod) % mod;
    }
    for(int i = 1;i <= 2e7;i++)
    { 
        c2[i] = (c2[i] + c2[i - 1] + mod) % mod;
        c1[i] = (c2[i] + c1[i] + mod) % mod;
    }
    for(int i = 1;i <= m;i++)
    {
        int k;
        cin >> k;
        cout << c1[k] << "\n";
    }
    return 0;
}