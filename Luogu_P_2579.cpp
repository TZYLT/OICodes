#include<bits/stdc++.h>
using namespace std;
template <unsigned N,unsigned M,class T>
struct Matrix{
    T d[N][M];
    unsigned n=N;
    unsigned m=M;
    T p=10000;
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
Matrix<50,50,int> A[12],SA,E,T;
int n,m,s,t,k,f;
int st[25],pos[25][4];
int main(){
    scanf("%d%d%d%d%d",&n,&m,&s,&t,&k);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        T.d[x][y]=T.d[y][x]=1;
    }
    scanf("%d",&f);
    for(int i=1;i<=f;i++){
        scanf("%d",st+i);
        for(int j=1;j<=st[i];j++)
            scanf("%d",&pos[i][j-1]);
    }
    for(int i=0;i<=11;i++){
        A[i]=T;
        set<int> s;
        for(int j=1;j<=f;j++)
            s.insert(pos[j][i%st[j]]);
        for(int c:s){
            for(int j=1;j<=n;j++)
                A[i].d[c][j-1]=0;
        }
        // for(int j=0;j<n;j++){
        //     for(int k=0;k<n;k++)
        //         printf("%d ",A[i].d[j][k]);
        //     printf("\n");
        // }printf("\n");
    }
    int tt=k/12;
    E.setIdentity();
    SA.setIdentity();
    for(int i=1;i<=11;i++)
        SA=SA*A[i];
    SA=SA*A[0];
    while(tt){
        if(tt&1)E=E*SA;
        SA=SA*SA;
    }
    for(int i=1;i<=(k%12);i++)
        E=E*A[i];
    for(int j=0;j<n;j++){
            for(int k=0;k<n;k++)
                printf("%d ",E.d[j][k]);
            printf("\n");
        }printf("\n");
    printf("%d",E.d[t][s]);
}