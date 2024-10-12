#include<bits/stdc++.h>
using namespace std;
int sum[10001000];
long long ans;
int n,k;
int main(){
    //freopen("alive.in","r",stdin);
    //freopen("alive.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum[i*i+j*j]++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(j*j+k-i*i>=0)ans+=sum[j*j+k-i*i];
    printf("%lld\n",ans);
}
