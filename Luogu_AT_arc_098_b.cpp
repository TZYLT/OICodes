#include<bits/stdc++.h>
using namespace std;
int n,a[200100];
int sum,xr;
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int l=1,r=0;l<=n;l++){
        while((sum+a[r+1])==(xr^a[r+1])&&r<n)r++,sum+=a[r],xr^=a[r];
        ans+=r-l+1;
        sum-=a[l];
        xr^=a[l];
    }
    printf("%lld\n",ans);
}