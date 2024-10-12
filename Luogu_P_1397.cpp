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

long long n,m;
int a,b,c,d;
string s,t;
Matrix<2,2,long long> qpow(Matrix<2,2,long long> A,string &s){
    Matrix<2,2,long long> T[10],E,P;
    T[0].setIdentity();E.setIdentity();P.setIdentity();
    for(int i=1;i<=9;i++)
        T[i]=T[i-1]*A;
    P=A;
    for(int i=s.size()-1;i>=0;i--){
        E=E*T[s[i]-'0'];
        Matrix<2,2,long long> p2=P*P;
        Matrix<2,2,long long> p4=p2*p2;
        P=p4*p4*p2;
        for(int j=1;j<=9;j++)
            T[j]=T[j-1]*P;
    }
    return E;
}
Matrix<2,2,long long> A,B,E,EA;
int main(){
    cin>>s>>t;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(int i=s.size()-1;i>=0;i--)
        if(s[i]=='0')s[i]='9';
        else {s[i]--;break;}
    for(int i=t.size()-1;i>=0;i--)
        if(t[i]=='0')t[i]='9';
        else {t[i]--;break;}    
    A.d[0][0]=a;A.d[0][1]=b;
    A.d[1][0]=0;A.d[1][1]=1;
    B.d[0][0]=c;B.d[0][1]=d;
    B.d[1][0]=0;B.d[1][1]=1;
    
    EA=qpow(A,t);
    E=qpow(EA*B,s)*EA;
    printf("%lld\n",(E.d[0][0]+E.d[0][1])%p);
}