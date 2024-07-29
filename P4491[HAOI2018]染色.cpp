#include<bits/stdc++.h>
using namespace std;
#define p 1004535809
#define g 3
#define M 10010000
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1)
            res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int rev[M],len,lim;
void NTT(int* a,int opt){
    len=__lg(lim);
    for(int i=0;i<lim;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
    //Warning:rev[] may been calculated many times
    for(int i=0;i<lim;++i)
        if(i<rev[i])
            swap(a[i],a[rev[i]]);
    for(int i=1;i<=len;i++){
        int m=1<<i;
        int wn=qpow(opt==1?g:qpow(g,p-2),(p-1)/m);
        for(int k=0;k<lim;k+=m){
            int w=1;
            for(int j=0;j<m/2;++j){
                int t=(long long)w*a[k+j+m/2]%p;
                int u=a[k+j];
                a[k+j]=((long long)u+t)%p;
                a[k+j+m/2]=((long long)u-t+p)%p;
                w=(long long)w*wn%p;
            }
        }
    }
    if(opt==-1){
        int inv=qpow(lim,p-2);
        for(int i=0;i<lim;i++)
            a[i]=(long long)a[i]*inv%p;
    }        
}
int n,m,s;
int w[M];
int inv[M],fac[M],ifac[M];
int a[M],b[M];
int C(int x,int y){return 1ll*fac[x]*ifac[y]%p*ifac[x-y]%p;}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<=m;i++)
        scanf("%d",w+i);
    inv[1]=1;
    for(int i=2;i<=max(n,m);++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    fac[0]=ifac[0]=1;
    for(int i=1;i<=max(n,m);i++)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    for(int i=0;i<=m&&s*i<=n;i++)
        a[i]=1ll*fac[i]*C(m,i)%p*C(n,i*s)%p*fac[s*i]%p*qpow(ifac[s],i)%p*qpow(m-i,n-s*i)%p;
    lim=min(m,n/s);
    for(int i=0;i<=lim;i++)
        b[i]=(i&1)?p-ifac[i]:ifac[i];
    
    reverse(a,a+lim+1);
    lim=(1<<(__lg(lim)+2)); 
    
    NTT(a,1);NTT(b,1);
    for(int i=0;i<lim;i++)
        a[i]=1ll*a[i]*b[i]%p;
    NTT(a,-1);
    
    lim=min(m,n/s);
    reverse(a,a+lim+1);
    int ans=0;
    for(int i=0;i<=lim;i++)   
        ans=(ans+1ll*a[i]*ifac[i]%p*w[i]%p)%p;
    printf("%d\n",ans);
}