#include<bits/stdc++.h>
using namespace std;
int a[501000],p[500500],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),p[a[i]+1]=i;
    long long ans=0;
    int l=n,r=1;
    for(int i=1;i<=n;i++){
        int id=p[i];
        l=min(l,id);r=max(r,id);
        ans+=(n-r+1)*l;
    }
    printf("%lld\n",ans);
}