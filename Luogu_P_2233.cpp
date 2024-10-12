#include<bits/stdc++.h>
using namespace std;
template <unsigned N,unsigned M,class T>
struct Matrix{
    T d[N][M];
    unsigned n=N;
    unsigned m=M;
    T p;
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
Matrix<8,8,int> E,T;
int t;
int main(){
    E.setIdentity();E.p=1000;
    scanf("%d",&t);
    T.d[1][0]=1;T.d[0][1]=1;
    T.d[2][1]=1;T.d[1][2]=1;
    T.d[3][2]=1;T.d[2][3]=1;
    T.d[4][3]=1;
                T.d[4][5]=1;
    T.d[6][5]=1;T.d[5][6]=1;
    T.d[7][6]=1;T.d[6][7]=1;
    T.d[0][7]=1;T.d[7][0]=1;
    T.p=1000;
    while(t){
        if(t&1)E=E*T;
        T=T*T;t>>=1;
    }
    printf("%d\n",E.d[4][0]);

}