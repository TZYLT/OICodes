#include<bits/stdc++.h>
using namespace std;
int a,st[1001000],h,n;
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        ans+=h;
        while(h&&st[h]<a)h--;
        st[++h]=a;
    }
    printf("%lld",ans);
}