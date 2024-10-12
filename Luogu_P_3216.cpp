#include<bits/stdc++.h>
using namespace std;
long long p;

template <unsigned N,unsigned M,class T>
struct Matrix{
    T d[N][M];
    unsigned n=N;
    unsigned m=M;
    void setClear(){
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                d[i][j]=0;
    }
    Matrix(){setClear();}
    void setIdentity(){
        setClear();
        for(unsigned i=0;i<min(n,m);i++)
            d[i][i]=1;
    }
    void operator=(const Matrix<N,M,T> &in){
        n=in.n;m=in.m;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                d[i][j]=in.d[i][j];
    }
    Matrix<N,M,T> operator+(const Matrix<N,M,T> &in){
        Matrix<N,M,T> t;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                t.d[i][j]=(d[i][j]+in.d[i][j])%p;
        return t;
    }
    Matrix<N,M,T> operator*(const T x){
        Matrix<N,M,T> t;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                t.d[i][j]=1ll*d[i][j]*x%p;
        return t;
    }
    template <unsigned P>
    Matrix<N,P,T> operator*(const Matrix<M,P,T> &in){
        Matrix<N,P,T> t;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                for(unsigned k=0;k<in.m;k++)
                    (t.d[i][k]+=1ll*d[i][j]*in.d[j][k]%p)%=p;
        return t;
    }
    void fiction(T f(T)){
    for(unsigned i=0;i<n;i++)
        for(unsigned j=0;j<m;j++)
            d[i][j]=f(d[i][j]);
    }
};
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a);
        a=(a*a);
        k>>=1;
    }
    return res;
}
long long qpowp(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
long long sol(long long n){
    long long len=0,t=n;
    while(t)len++,t/=10;
    long long f=0;
    if(len>=2)f=sol(qpow(10,len-1)-1);
    long long rem=(n-(qpow(10,len-1)-1));
    Matrix<3,3,long long> E,A;
    E.setIdentity();
    A.d[0][0]=(qpowp(10,len))%p;A.d[0][1]=1;A.d[0][2]=1;
    A.d[1][0]=0;A.d[1][1]=1;A.d[1][2]=1;
    A.d[2][0]=0;A.d[2][1]=0;A.d[2][2]=1;
    Matrix<3,1,long long> I;
    I.d[0][0]=f;I.d[1][0]=(qpowp(10,len-1)-1)%p;I.d[2][0]=1;

    while(rem){
        if(rem&1)E=E*A;
        A=A*A;rem>>=1;
    }
    I=E*I;
    return I.d[0][0];
}
long long n;
int main(){
    scanf("%lld%lld",&n,&p);
    printf("%lld\n",sol(n));
}