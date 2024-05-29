#include<bits/stdc++.h>
using namespace std;
#define p 998244353
#define g 3
#define M 100100
int w[M],we[M],n,k;
int f[M];
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
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
void mg(int l,int r,int *x){
    
    if(l==r){
		x[0]=1;x[1]=1;
		return;
	}
    int mid=(l+r)>>1;
    int y[M];
    memset(y,0,sizeof(y));
    mg(l,mid,x);
    mg(mid+1,r,y);
    lim=(1<<(__lg(r-l+2)+2));
   
    // printf("\n");
    // printf("[%d,%d:%d]:",l,r,lim);
    // printf("\n");
    // for(int i=0;i<=n;i++)
    //     printf("%d ",x[i]);
    // printf("\n");    
    // for(int i=0;i<=n;i++)
    //     printf("%d ",y[i]);
    // printf("\n");    

    NTT(x,1);
    NTT(y,1);
    for(int i=0;i<lim;i++)
        x[i]=1ll*x[i]*y[i]%p;
    NTT(x,-1);
}

int main(){
    scanf("%d%d",&n,&k);
    // for(int i=1;i<=n;i++){
    //     int x,y;
    //     scanf("%d%d",&x,&y);
    //     w[i]=1ll*x*qpow(y,p-2)%p;
    //     we[i]=(1ll+p+p-w[i])%p;
    // }
    mg(1,n,f);
    //for(int i=0;i<=n;i++)
        printf("%d ",f[k]);
}