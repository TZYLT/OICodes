#include<bits/stdc++.h>
using namespace std;
int a,m,b;
int phi=1;
int v[1001000],p[1000100],k;
void linearSieve(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
long long ppow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=res*a;
        a=a*a;
        k>>=1;
    }
    return res;
}
void fac(int x){
    for(int i=1;i<=k;i++){
        if(x==1)break;
        int c=0;
        while((x%p[i])==0&&x>1)c++,x=x/p[i];
        if(c>0)phi*=ppow(p[i],c-1)*(p[i]-1);
    }
    if(x>1)phi*=x-1;
}
long long qpow(long long a,long long k,long long p){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char *p1,*p2,buf[(1<<20)+5];
int f=0;
inline int read(){
    int x=0;long long t=0;char c=gc();
    while(!isdigit(c)) c=gc();
    while(isdigit(c)){
        x=(1ll*x*10%phi+(c^48))%phi;
        t=t*10+(c^48);
        if(t>=phi)f=1;
        c=gc();
    }
    return x;
}
int main(){
    scanf("%d%d",&a,&m);
    linearSieve(100000);
    fac(m);
    b=read();
    if(__gcd(a,m)==1)cout<<qpow(a,b,m)<<endl;
    else if(f==1)cout<<qpow(a,b+phi,m)<<endl;
    else cout<<qpow(a,b,m)<<endl;
}
