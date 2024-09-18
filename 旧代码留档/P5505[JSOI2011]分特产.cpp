#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int n,m;
int a[1010];
int inv[2020],fac[2020],ifac[2020];
int C(int x,int y){return 1ll*fac[x]*ifac[y]%p*ifac[x-y]%p;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)   
        scanf("%d",a+i);
    fac[0]=ifac[0]=inv[1]=1;
    for(int i=2;i<=2000;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=2000;i++)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    int ans=0;
    for(int i=1;i<=n;i++){
        int tp=1;
        for(int j=1;j<=m;j++)  
            tp=1ll*tp*C(a[j]+i-1,i-1)%p;
        ans=(ans+1ll*C(n,i)*tp*(((n-i)&1)?-1:1))%p;
    }
    printf("%d\n",(ans+p)%p);   
}