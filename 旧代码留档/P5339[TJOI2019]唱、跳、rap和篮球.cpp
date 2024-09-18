#include<bits/stdc++.h>
using namespace std;
#define p 998244353
#define M (1<<16)
#define g 3 
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
int inv[M],fac[M],ifac[M];
int sum(int a,int b,int c,int d,int n){
    int A[M]={0},B[M]={0},C[M]={0},D[M]={0};
    for(int i=0;i<=a;i++)A[i]=ifac[i];
    for(int i=0;i<=b;i++)B[i]=ifac[i];
    for(int i=0;i<=c;i++)C[i]=ifac[i];
    for(int i=0;i<=d;i++)D[i]=ifac[i];
    NTT(A,1);NTT(B,1);NTT(C,1);NTT(D,1);
    for(int i=0;i<lim;i++)
        A[i]=1ll*A[i]*B[i]%p*C[i]%p*D[i]%p;
    NTT(A,-1);
    return 1ll*A[n]*fac[n]%p;
}

int C(int x,int y){return 1ll*fac[x]*ifac[y]%p*ifac[x-y]%p;}
int n,a,b,c,d;
int main(){
    inv[1]=1;
    for(int i=2;i<=10000;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    fac[0]=ifac[0]=1;
    for(int i=1;i<=10000;i++)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;

    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    lim=(1<<(__lg(max({n,a,b,c,d}))+3));
    len=__lg(lim);
    for(int i=0;i<lim;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
    
    int ans=0;
    for(int i=0;i<=n;i++)
        if(a-i>=0&&b-i>=0&&c-i>=0&&d-i>=0&&n-4*i>=0)
            ans=(ans+1ll*((i&1)?-1ll:1ll)*C(n-3*i,i)*sum(a-i,b-i,c-i,d-i,n-4*i)%p)%p;
    printf("%d\n",(ans+p)%p);
}