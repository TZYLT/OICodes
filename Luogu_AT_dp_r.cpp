#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
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
        t.n=n;t.m=in.m;
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
Matrix<50,50,long long> A,E;
long long n,t;
int main(){
    scanf("%lld%lld",&n,&t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&A.d[i-1][j-1]);
    A.n=A.m=n;E.setIdentity();
    while(t){
        if(t&1)E=E*A;
        A=A*A;t>>=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            (ans+=E.d[i-1][j-1])%=p;
    printf("%d",ans);
}