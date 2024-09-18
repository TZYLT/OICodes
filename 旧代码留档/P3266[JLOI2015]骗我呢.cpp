#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int n,m;
int inv[4001000],fac[4001000],ifac[4001000];
void rev1(int &x,int &y){swap(x,y);x--;y++;}
void rev2(int &x,int &y){swap(x,y);y-=m+2;x+=m+2;}
int C(int x,int y){return (x<0||y<0)?0:(1ll*fac[x+y]*ifac[x]%p)*ifac[y]%p;}
int sol(void){
    int ans=0;
    int x=n+m+1,y=n;
    ans=C(x,y);
    while(x>=0&&y>=0){
        rev1(x,y);ans=(ans-C(x,y)+p)%p;
        rev2(x,y);ans=(ans+C(x,y))%p;
    }
    x=n+m+1,y=n;
    while(x>=0&&y>=0){
        rev2(x,y);ans=(ans-C(x,y)+p)%p;
        rev1(x,y);ans=(ans+C(x,y))%p;
    }
    return ans;
}

int main(){
    inv[0]=fac[0]=ifac[0]=inv[1]=1;
    for(int i=2;i<=4000000;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=4000000;++i)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    scanf("%d%d",&n,&m);
    printf("%d\n",sol());

}