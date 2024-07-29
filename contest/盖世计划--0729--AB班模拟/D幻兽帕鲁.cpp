#include<bits/stdc++.h>
using namespace std;
#define M 20020
int n,m;
int a[M],b[M];
int main(){
    freopen("pal.in","r",stdin);
    freopen("pal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            for(int i=l;i<=r;i++)
                a[i]=x;
        }else {
            long long ans=0x7f7f7f7f;
            int l,r;
            scanf("%d%d",&l,&r);
            for(int i=l;i<=r;i++){
                int t=__gcd(a[i],b[i]);
                ans=min(ans,1ll*a[i]*b[i]/t/t);
            }
            printf("%lld\n",ans);
        }
    }
}