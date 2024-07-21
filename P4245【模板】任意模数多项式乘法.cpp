#include<bits/stdc++.h>
using namespace std;
#define M (1<<20)
const int mod[3]={998244353,1004535809,469762049};
inline long long qpow(long long a,long long k,long long p){
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
inline void NTT(int* a,int opt,int g,int p){
    len=__lg(lim);
    for(int i=0;i<lim;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
    //Warning:rev[] may been calculated many times
    for(int i=0;i<lim;++i)
        if(i<rev[i])
            swap(a[i],a[rev[i]]);
    for(int i=1;i<=len;i++){
        int m=1<<i;
        int wn=qpow(opt==1?g:qpow(g,p-2,p),(p-1)/m,p);
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
        int inv=qpow(lim,p-2,p);
        for(int i=0;i<lim;i++)
            a[i]=(long long)a[i]*inv%p;
    }        
}

int n,m,pp;
int f1[M],f2[M],f3[M],g1[M],g2[M],g3[M];
int main(){
    scanf("%d%d%d",&n,&m,&pp);
    lim=1<<(__lg(n+m)+2);

    for(int i=0;i<=n;i++)
        scanf("%d",&f1[i]),f2[i]=f1[i],f3[i]=f1[i];
    for(int i=0;i<=m;i++)
        scanf("%d",&g1[i]),g2[i]=g1[i],g3[i]=g1[i];  
    
    NTT(f1,1,3,mod[0]);
    NTT(f2,1,3,mod[1]);
    NTT(f3,1,3,mod[2]);
    NTT(g1,1,3,mod[0]);
    NTT(g2,1,3,mod[1]);
    NTT(g3,1,3,mod[2]);
    
    for(int j=0;j<lim;j++)    
        f1[j]=1ll*f1[j]*g1[j]%mod[0];
    for(int j=0;j<lim;j++)    
        f2[j]=1ll*f2[j]*g2[j]%mod[1];
    for(int j=0;j<lim;j++)    
        f3[j]=1ll*f3[j]*g3[j]%mod[2];

    NTT(f1,-1,3,mod[0]);
    NTT(f2,-1,3,mod[1]);
    NTT(f3,-1,3,mod[2]);

    //int c1,c2,c3;
    //c1=1ll*mod[1]%pp*1ll*mod[2]%pp*1ll*qpow(1ll*mod[1]%mod[0]*mod[2]%mod[0],mod[0]-2,mod[0])%pp;
    //c2=1ll*mod[0]%pp*1ll*mod[2]%pp*1ll*qpow(1ll*mod[0]%mod[1]*mod[2]%mod[1],mod[1]-2,mod[1])%pp;
    //c3=1ll*mod[0]%pp*1ll*mod[1]%pp*1ll*qpow(1ll*mod[0]%mod[2]*mod[1]%mod[2],mod[2]-2,mod[2])%pp;
    long long inv_1=qpow(mod[0],mod[1]-2,mod[1]);
    long long inv_2=qpow(1ll*mod[1]*mod[0]%mod[2],mod[2]-2,mod[2]);
    for(int i=0;i<n+m+1;i++){
        //int ans=0;
        //ans=(1ll*ans+1ll*f1[i]*c1%pp)%pp;
        //ans=(1ll*ans+1ll*f2[i]*c2%pp)%pp;
        //ans=(1ll*ans+1ll*f3[i]*c3%pp)%pp;
        long long x =1ll*(f2[i]-f1[i]+mod[1])%mod[1]*inv_1%mod[1]*mod[0]+f1[i];
		long long ans=(1ll*(f3[i]-x%mod[2]+mod[2])%mod[2]*inv_2%mod[2]*(1ll*mod[0]*mod[1]%pp)%pp+x)%pp;
		//long long x=1ll*(1ll*f2[i]-f1[i]+mod[1])%mod[1]*qpow(mod[0],mod[1]-2,mod[1])%mod[1]*mod[0]+f1[i];
		//long long ans=(1ll*(1ll*f3[i]-x%mod[2]+mod[2])%mod[2]*qpow(1ll*mod[0]*mod[1]%mod[2],mod[2]-2,mod[2])%mod[2]*((1ll*mod[0]*mod[1]%mod[2])%pp)%pp+x)%pp;
        printf("%d ",ans);
        //printf("[%d %d %d:%lld]",f1[i],f2[i],f3[i],ans);
    }
}