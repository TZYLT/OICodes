#include<bits/stdc++.h>
using namespace std;
#define M ((1<<21))
int f[M],ft[M],ans[M];
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
void mul(int len,int *a,int *b){
    lim=1<<(__lg(len)+2);
    NTT(a,1);
    NTT(b,1);
    for(int i=0;i<lim;i++)
        a[i]=1ll*a[i]*b[i]%p;
    NTT(a,-1);
}
string s;
int main(){

    cin>>s;
    for(int i=s.size()-1;i>=0;i--)
        f[s.size()-i-1]=s[i]-'0';
    int n=s.size()*3;

    memset(ans,0,sizeof(ans));
    ans[0]=1;

    for(int i=0;i<(1<<(__lg(n)+2));i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
        
    for(int i=0;i<M;i++)ft[i]=0;
    for(int i=0;i<n;i++)
        ft[i]=f[i];
    ft[0]+=1;
    mul(n,ans,ft);

    for(int i=0;i<M;i++)ft[i]=0;
    for(int i=0;i<n;i++)
        ft[i]=f[i];
    ft[0]+=2;
    mul(n,ans,ft);

    for(int i=0;i<M;i++)ft[i]=0;
    for(int i=0;i<n;i++)
        ft[i]=f[i];
    ft[0]+=3;
    mul(n,ans,ft);

    for(int i=0;i<M;i++)ft[i]=0;
    for(int i=0;i<n;i++)
        ft[i]=f[i];
    ft[0]+=4;
    mul(n,ans,ft);

    for(int i=0;i<=n*4;i++)
        ans[i+1]+=ans[i]/10,ans[i]%=10;

    for(int i=n*4;i>0;i--){
        ans[i-1]+=10*(ans[i]%6);
        ans[i]/=6;
    }
    ans[0]/=6;
    for(int i=n*4;i>0;i--){
        ans[i-1]+=10*(ans[i]%4);
        ans[i]/=4;
    }
    ans[0]/=4;

     for(int i=0;i<=n*4;i++)
         ans[i+1]+=ans[i]/10,ans[i]%=10;

    int flag=0;
    for(int i=n*4;i>=0;i--){
        if(ans[i]!=0)flag=1;
        if(flag)printf("%d",ans[i]);
    }
        
}