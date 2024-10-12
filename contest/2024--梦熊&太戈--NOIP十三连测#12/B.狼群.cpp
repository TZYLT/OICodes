#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int inv[400100],fac[400100],ifac[400100];
int C(int x,int y){
    if(x-y<0||y<0)return 0;
    return 1ll*fac[x]*ifac[y]%p*ifac[x-y]%p;
}
int n,m;
pair<int,int> dt[1001],tq[1001];
int main(){
    // freopen("wolf.in","r",stdin);
    // freopen("wolf.out","w",stdout);
    inv[1]=1;
    for(int i=2;i<=300000;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    fac[0]=ifac[0]=1;
    for(int i=1;i<=300000;i++)
        fac[i]=1ll*fac[i-1]*i%p;
    for(int i=1;i<=300000;i++)
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&dt[i].first,&dt[i].second);
    if(m&1){
        for(int i=1;i<=n;i++){
            if((dt[i].first+dt[i].second)%2==0){
                printf("0\n");
                return 0;
            }
            tq[i].first=ceil(((double)dt[i].first+dt[i].second)/2);
            tq[i].second=ceil(((double)dt[i].first-dt[i].second)/2);
        }
        int lx=-200000,rx=200000,ly=-200000,ry=200000;
        int ansx=0,ansy=0;
        for(int i=lx;i<=rx;i++){
            int ans=1;
            for(int j=1;j<=n;j++)
                ans=1ll*ans*C(m,abs(i-tq[j].first)+(m-1)/2)%p;
            (ansx+=ans)%=p;

        }
        for(int i=ly;i<=ry;i++){
            int ans=1;
            for(int j=1;j<=n;j++)
                ans=1ll*ans*C(m,abs(i-tq[j].second)+(m-1)/2)%p;
            (ansy+=ans)%=p;
        }
        printf("%lld",1ll*(ansx-1)*(ansy-1)%p);
    }else{
        for(int i=1;i<=n;i++){
            if((dt[i].first+dt[i].second)%2==1){
                printf("0\n");
                return 0;
            }
            tq[i].first=(dt[i].first+dt[i].second)/2;
            tq[i].second=(dt[i].first-dt[i].second)/2;
        }
        int lx=-200000,rx=200000,ly=-200000,ry=200000;
        //printf("%d %d %d %d\n",lx,rx,ly,ry);
        int ansx=0,ansy=0;
        for(int i=lx;i<=rx;i++){
            int ans=1;
            for(int j=1;j<=n;j++)
                ans=1ll*ans*C(m,abs(i-tq[j].first)+m/2)%p;
            (ansx+=ans)%=p;
        }
        for(int i=ly;i<=ry;i++){
            int ans=1;
            for(int j=1;j<=n;j++)
                ans=1ll*ans*C(m,abs(i-tq[j].second)+m/2)%p;
            (ansy+=ans)%=p;
        }
        printf("%lld",1ll*ansx*ansy%p);
    }
}