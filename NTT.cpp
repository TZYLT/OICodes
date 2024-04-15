#include<bits/stdc++.h>
using namespace std;
#define p $0
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
int rev[$1],len,lim=$2;
void NTT(int* a,int opt,int g){
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
int n,m;
int f[1<<22],g[1<<22];
int main(){
    scanf("%d%d",&n,&m);
    lim=1<<(__lg(n+m+10)+1);
    for(int i=0;i<=n;i++)   
        scanf("%d",&f[i]);
    for(int i=0;i<=m;i++)   
        scanf("%d",&g[i]);
    NTT(f,1,3);
    NTT(g,1,3);
    for(int i=0;i<lim;i++)
        f[i]=(long long)f[i]*g[i]%998244353;
    NTT(f,-1,3);
    for(int i=0;i<=n+m;i++)
        printf("%d ",(f[i]%998244353+998244353)%998244353);
}