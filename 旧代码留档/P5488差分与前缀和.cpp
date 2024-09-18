#include<bits/stdc++.h>
using namespace std;

#define p 1004535809
#define g 3
#define M (1<<19)

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
bool sd;
int a[M],b[M],inv[M],ifac[M],kp[M];
int n,k,t;
string s;
int main(){
    cin>>n;
    cin>>s;
    cin>>t;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    sd=1;
    
    for(int i=s.size()-1,j=1;i>=0;i--){
        k=((long long)k+(long long)j*(s[i]-'0'))%p;
        j=(10ll*(long long)j)%p;
    }
    ifac[0]=ifac[1]=inv[1]=1;
    for(int i=2;i<=n+114;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    lim=1<<(__lg(n)+2);
    if(t==0){
        kp[0]=1;
        for(int i=1;i<n;i++)
            kp[i]=1ll*kp[i-1]*((k+i-1)%p)%p;
        for(int i=0;i<n;i++)
            kp[i]=1ll*kp[i]*ifac[i]%p;
    }else{
        kp[0]=1;
        for(int i=1;i<n;i++)
            kp[i]=1ll*kp[i-1]*(((k-i+1)%p+p)%p)%p;
        for(int i=0;i<n;i++)
            kp[i]=1ll*kp[i]*ifac[i]%p; 
        for(int i=0;i<n;i++){
            kp[i]=sd?kp[i]:((p-kp[i])%p);
            sd^=1;
        }
    }
    NTT(kp,1);
    NTT(a,1);
    for(int i=0;i<lim;i++) 
        a[i]=1ll*a[i]*kp[i]%p;
    NTT(a,-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}