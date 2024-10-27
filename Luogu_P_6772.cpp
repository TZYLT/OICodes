#include<bits/stdc++.h>
using namespace std;
template <unsigned N,unsigned M,class T>
struct Matrix{
    T d[N][M];
    unsigned n=N;
    unsigned m=M;
    void setClear(){
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                d[i][j]=0xcfcfcfcfcfcfcfcf;
    }
    Matrix(){setClear();}
    void setIdentity(){
        setClear();
        for(unsigned i=0;i<min(n,m);i++)
            d[i][i]=0;
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
                t.d[i][j]=max(d[i][j],in.d[i][j]);
        return t;
    }
    Matrix<N,M,T> operator*(const T x){
        Matrix<N,M,T> t;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                t.d[i][j]=1ll*d[i][j]*x;
        return t;
    }
    template <unsigned P>
    Matrix<N,P,T> operator*(const Matrix<M,P,T> &in){
        Matrix<N,P,T> t;
        t.n=n;t.m=in.m;
        for(unsigned i=0;i<n;i++)
            for(unsigned j=0;j<m;j++)
                for(unsigned k=0;k<in.m;k++){
                    if(d[i][j]<0||in.d[j][k]<0)continue;
                    t.d[i][k]=max(t.d[i][k],d[i][j]+in.d[j][k]);
                }
        return t;
    }
    void fiction(T f(T)){
    for(unsigned i=0;i<n;i++)
        for(unsigned j=0;j<m;j++)
            d[i][j]=f(d[i][j]);
    }
};
int n,m,t,k;
Matrix<250,250,long long> A[40];
Matrix<250,1,long long> E;
int cost,st;
void qpow(int a,Matrix<250,1,long long>& E){
    //cost-=clock();
    for(int i=0;i<=30;i++)
        if((a>>i)&1)
            E=A[i]*E;
    //cost+=clock();
}
inline int id(int x,int st){
    return (x-1)*5+st;
}
int w[10010];

pair<int,pair<int,int> > qs[10010];
int main(){
    scanf("%d%d%d%d",&n,&m,&t,&k);
    //st-=clock();
    E.setClear();E.n=n*5;
    A[0].n=A[0].m=n*5;
    E.d[id(1,1)][0]=0;
    //st+=clock();
    for(int i=1;i<=n;i++){
        scanf("%d",w+i);
        A[0].d[id(i,0)][id(i,1)]=w[i];
        A[0].d[id(i,1)][id(i,2)]=0;
        A[0].d[id(i,2)][id(i,3)]=0;
        A[0].d[id(i,3)][id(i,4)]=0;
    }
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(z!=1)A[0].d[id(y,z-1)][id(x,0)]=0;
        else A[0].d[id(y,0)][id(x,0)]=w[y];
    }
    //st-=clock();
    for(int i=1;i<=30;i++)
        A[i]=A[i-1]*A[i-1];
    
    if(k>=1){
        for(int i=1;i<=k;i++)
            scanf("%d%d%d",&qs[i].first,&qs[i].second.first,&qs[i].second.second);
        sort(qs+1,qs+1+k);
        qpow(qs[1].first+1,E);
        E.d[id(qs[1].second.first,0)][0]+=qs[1].second.second;
        for(int i=2;i<=k;i++){
            qpow(qs[i].first-qs[i-1].first,E);
            E.d[id(qs[i].second.first,0)][0]+=qs[i].second.second;
        }
        qpow(t-qs[k].first,E);
    }else{
        qpow(t+1,E);
    }//pp(E);
    //st+=clock();
    printf("%lld\n",E.d[id(1,0)][0]<0?-1:E.d[id(1,0)][0]);
    //printf("%dms,%dms\n",cost,st);
}