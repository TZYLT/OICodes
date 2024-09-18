#include<bits/stdc++.h>
using namespace std;
#define p 998244353
#define int long long
vector<int> eg[1001000];
int f[1001000],g[1001000];
int id,n,m;
signed main(){
    scanf("%lld%lld%lld",&id,&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        eg[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        f[i]=(eg[i].size()+1);
        for(int c:eg[i])
            f[i]=(f[i]+(g[i-1]-g[c-1])%p+p)%p;
        g[i]=(g[i-1]+f[i]+p)%p;
    }
    printf("%lld\n",(g[n]+p)%p);
}