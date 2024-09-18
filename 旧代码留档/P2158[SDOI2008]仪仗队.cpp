#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 40010;
ll e[maxn];
int main(){
    ll n, ans = 2;
    cin >> n;
    if (n == 1){
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        e[i] = i;
    for (int i = 2; i <= n; ++i)
        if (e[i] == i)       
            for (int j = i; j <= n; j += i)
                e[j] = e[j] / i * (i - 1);
    --n;
    for (int i = 2; i <= n; ++i)
        ans += e[i] * 2;
    cout << ans + 1;
    return 0;
}