#include<bits/stdc++.h>
using namespace std;
#define int long long
template <unsigned N,unsigned M,class T>
struct Matrix{
    T d[N][M];
    unsigned n=N;
    unsigned m=M;
    const T p=10000;
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
Matrix<50,50,int> A[12],SA,E,T;
int n,m,s,t,K,f;
int st[25],pos[25][4];
signed main(){
    scanf("%lld%lld%lld%lld%lld",&n,&m,&s,&t,&K);
    //T.n=T.m=E.n=E.m=SA.n=SA.m=n;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        T.d[x][y]=T.d[y][x]=1;
    }
    scanf("%lld",&f);
    for(int i=1;i<=f;i++){
        scanf("%lld",st+i);
        for(int j=1;j<=st[i];j++)
            scanf("%lld",&pos[i][j-1]);
    }
    for(int i=0;i<=11;i++){
        A[i]=T;
        set<int> S;
        for(int j=1;j<=f;j++)
           S.insert(pos[j][i%st[j]]);
        for(int c:S){
            for(int j=1;j<=n;j++)
                A[i].d[c][j-1]=0;
        }
    }
    int tt=K/12;
    E.setIdentity();
    SA.setIdentity();
    for(int i=1;i<=11;i++)
        SA=A[i]*SA;
    SA=A[0]*SA;
    while(tt){
        if(tt&1)E=SA*E;
        SA=SA*SA;tt>>=1;
    }
    for(int i=1;i<=(K%12);i++)
        E=A[i]*E;
    printf("%lld",E.d[t][s]);
}
