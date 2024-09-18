#include<bits/stdc++.h>
using namespace std;
#define M (1<<18)

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
int t[M];
void polyinv(int len,int *a,int *b){
    if(len==1){
        b[0]=1;
        return;
    }
    polyinv((len+1)>>1,a,b);
    int l=1;
    while(l<=(len<<1))l<<=1;
    for(int i=0;i<len;i++)t[i]=a[i];
    for(int i=len;i<l;i++)t[i]=0;
    lim=l;
    NTT(t,1),NTT(b,1);
    for(int i=0;i<l;i++)
        b[i]=1ll*(2-1ll*t[i]*b[i]%p+p)%p*b[i]%p;
    NTT(b,-1);
    for(int i=len;i<l;i++)b[i]=0;
}
int b[M],f[M],n,top;
int main(){
    scanf("%d",&n);
    f[0]=1;
    for(int i=1;i<n;i++)
        scanf("%d",&f[i]);
    for(int i=1;i<n;i++)
        f[i]=p-f[i];

    polyinv(n,f,b);
    for(int i=0;i<n;i++)
        printf("%d ",b[i]);
    
}