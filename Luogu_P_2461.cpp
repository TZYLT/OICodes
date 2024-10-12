#include<bits/stdc++.h>
using namespace std;
int p;
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
int k,b[101],c[101];
long long n,m;
Matrix<16,16,int> E,A,I;
int sol(long long n){
    if(n<=k){
        int ans=0;
        for(int i=1;i<=n;i++)
            (ans+=b[i])%=p;
        return ans;
    }
    E.setIdentity();A.setClear();I.setClear();
    E.n=E.m=k+1;A.n=A.m=k+1;I.n=k+1;I.m=1;

    A.d[0][0]=1;
    for(int i=1;i<=k;i++)
        A.d[0][i]=A.d[1][i]=c[i];
    for(int i=1;i<k;i++)
        A.d[i+1][i]=1;
    
    n-=k;
    while(n){
        if(n&1)E=E*A;
        A=A*A;n>>=1;
    }
    for(int i=1;i<=k;i++)
        (I.d[0][0]+=b[i])%=p;
    for(int i=1;i<=k;i++)
        I.d[i][0]=b[k-i+1];
    I=E*I;
    return I.d[0][0];
}
int main(){
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
        scanf("%d",b+i);
    for(int i=1;i<=k;i++)
        scanf("%d",c+i);
    scanf("%lld%lld%d",&m,&n,&p);
    printf("%d\n",((sol(n)-sol(m-1))%p+p)%p);
}
