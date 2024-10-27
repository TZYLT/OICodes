#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100100],l[100100],r[100100];
int sum[100100];
int st[100100],h;
long long ans=0;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        while(h&&a[st[h]]>=a[i])h--;
        l[i]=st[h];
        st[++h]=i;
    }
    h=0;
    for(int i=n;i>=1;i--){
        while(h&&a[st[h]]>=a[i])h--;
        if(h)r[i]=st[h];
        else r[i]=n+1;
        st[++h]=i;
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,1ll*(sum[r[i]-1]-sum[l[i]])*a[i]);
    printf("%lld\n",ans);
}