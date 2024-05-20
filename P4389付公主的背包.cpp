#include<bits/stdc++.h>
using namespace std;
#define M (1<<13)

#define p 998244353
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
int b[M],t[M],l;
void polyinv(int len,int* a){
    l=__lg(len);
    b[0]=qpow(a[0],p-2);
    for(int i=1;i<=l;i++){
        lim=(1<<i);
        NTT(b,1);
        for(int j=0;j<len;j++)
            t[j]=a[j];
        NTT(t,1);
        for(int j=0;j<len;j++)
            b[j]=((2ll*b[j])%p+(1ll*b[j]*b[j])%p*t[j]%p);
        NTT(b,-1);
    }
}
int f[M],n,m,top;
int main(){
    scanf("%d%d",&n,&m);
    top=__lg(m)+2;
    for(int i=1,v;i<=n;i++){
        scanf("%d",&v);
        f[v]=1;
    }
    for(int i=0;i<top;i++)
        f[i]=(-f[i]+p)%p;
    f[0]=(f[0]+1+p)%p;
    polyinv((1<<top),f);
    for(int i=1;i<=m;i++)
        printf("%d\n",f[i]);
    
}