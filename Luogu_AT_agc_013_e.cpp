#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
int x[M],n,m,now[4][4],a[4][4],ans[4],b[4][4];
void init()
{
    a[1][1] = 1;a[1][3] = 1;
    a[2][1] = 2;a[2][2] = 1;a[2][3] = 2;
    a[3][1] = 1;a[3][2] = 1;a[3][3] = 2;

    b[1][1] = 1;
    b[2][1] = 2;b[2][2] = 1;
    b[3][1] = 1;b[3][2] = 1;b[3][3] = 1;
}
void mulip1()
{
    int res[4];
    memset(res,0,sizeof(res));
    //res[1] = ans[1];res[2] = ans[2];res[3] = ans[3];
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 1;j <= 3;j++)
        {
            res[i] = (res[i] + (now[i][j] * ans[j] % mod)) % mod;
        }
    }
    ans[1] = res[1];ans[2] = res[2];ans[3] = res[3];
}
void mulip2()
{
    int res[4][4];
    memset(res,0,sizeof(res));
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 1;j <= 3;j++)
        {
            for(int z = 1;z <= 3;z++)
            {
                res[i][j] = (res[i][j] + (now[i][z] * a[z][j] % mod)) % mod;
            }
        }
    }
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 1;j <= 3;j++) now[i][j] = res[i][j];
    }
}
void fastpow(int x)
{
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 1;j <= 3;j++) now[i][j] = a[i][j];
    }
    while(x)
    {
       if(x & 1) mulip1(); 
       x >>= 1;
       mulip2();
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> x[i];
    int len = m;
    ans[1] = 1;
    for(int i = 1;i <= len;i++)
    {
        int cha;
        if(i == 1) cha = x[i];
        else cha = x[i] - x[i - 1] - 1;
        fastpow(cha);
        int res[4] = {0};
        for(int j = 1;j <= 3;j++)
        {
            for(int z = 1;z <= 3;z++)
            {
                res[j] = (res[j] + (b[j][z] * ans[z] % mod))%mod;
            }
        }
        ans[1] = res[1];ans[2] = res[2];ans[3] = res[3];
    }
    if(x[m] < n) fastpow(n - x[m] - 1);
    cout << ans[3];
    return 0;
}