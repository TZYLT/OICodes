#include<bits/stdc++.h>
using namespace std;
long long p;
inline long long quickMul (long long a, long long b) {
	long long res = 0;
	a %= p;
	b %= p;
	while (b) {
		if (b & 1)
			res = (res + a) % p;
		b >>= 1;
		a = (a + a) % p;
	}
	return res;
}
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
                    (t.d[i][k]+=quickMul(d[i][j],in.d[j][k]))%=p;
        return t;
    }
    void fiction(T f(T)){
    for(unsigned i=0;i<n;i++)
        for(unsigned j=0;j<m;j++)
            d[i][j]=f(d[i][j]);
    }
};
Matrix<11,11,long long> E,A;
Matrix<11,1,long long> I;
long long n,P,q,r,t,u,v,w,x,y,z;
int main(){
    E.setIdentity();
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&n,&p,&P,&q,&r,&t,&u,&v,&w,&x,&y,&z);
    A.d[0][0]=P;A.d[0][1]=q;A.d[0][2]=1;A.d[0][4]=1;A.d[0][8]=r;A.d[0][9]=t;A.d[0][10]=1;
    A.d[1][0]=1;
    A.d[2][0]=1;A.d[2][2]=u;A.d[2][3]=v;A.d[2][4]=1;A.d[2][6]=1;
    A.d[3][2]=1;
    A.d[4][0]=1;A.d[4][2]=1;A.d[4][4]=x;A.d[4][5]=y;A.d[4][7]=1;A.d[4][9]=1;A.d[4][10]=2;
    A.d[5][4]=1;
    A.d[6][6]=w;
    A.d[7][7]=z;
    A.d[8][8]=1;A.d[8][9]=2;A.d[8][10]=1;
    A.d[9][9]=1;A.d[9][10]=1;
    A.d[10][10]=1;
    I.d[0][0]=3;I.d[1][0]=1;I.d[2][0]=3;I.d[3][0]=1;I.d[4][0]=3;I.d[5][0]=1;I.d[6][0]=w;I.d[7][0]=z;I.d[8][0]=1;I.d[9][0]=1;I.d[10][0]=1;
    n-=2;
    while(n){
        if(n&1)E=E*A;
        A=A*A;n>>=1;
    }
    I=E*I;
    printf("nodgd %lld\nCiocio %lld\nNicole %lld\n",I.d[0][0],I.d[2][0],I.d[4][0]);

}