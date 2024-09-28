#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
template <unsigned M,unsigned N,class T>
class Matrix{
	public:
	T Data[M][N];
	unsigned n=N;
	unsigned m=M;
	
	public:
		Matrix()=default;
		Matrix& setClear(void);
		Matrix& setData(unsigned m,unsigned n,T inData);
		Matrix& setAllData(T inData);
		
		T& readData(unsigned m,unsigned n);
		int readh(void);
		int readl(void);
		
		Matrix operator+(Matrix<M,N,T> in);
		template <unsigned P>
			Matrix<M,P,T> operator*(Matrix<N,P,T> in);
		Matrix operator*(T in);
		Matrix fiction(T f(T));
};

template <unsigned M,unsigned N,class T>
Matrix<M,N,T>& Matrix<M,N,T>::setClear(void){
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			Data[i][j]=0;
	return *this; 
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T>& Matrix<M,N,T>::setData(unsigned m,unsigned n,T inData){
	Data[m-1][n-1]=inData;
	return *this;
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T>& Matrix<M,N,T>::setAllData(T inData){
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			Data[i][j]=inData;	
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T> Matrix<M,N,T>::operator+(Matrix<M,N,T> in){
	Matrix<M,N,T> ADD;
	ADD.setClear();
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			ADD.Data[i][j]=(Data[i][j]+in.Data[i][j])%p;
	return ADD;
}

template <unsigned M,unsigned N,class T>
	template <unsigned P>
Matrix<M,P,T> Matrix<M,N,T>::operator*(Matrix<N,P,T> in){
	Matrix<M,P,T> ADD;
	ADD.setClear();
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<P;k++)
				ADD.Data[i][k]=(ADD.Data[i][k]+1ll*Data[i][j]*in.Data[j][k]%p)%p;
	return ADD;
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T> Matrix<M,N,T>::operator*(T in){
	Matrix<M,N,T> ADD;
	ADD.setClear();
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			ADD.Data[i][j]=Data[i][j]*in;
	return ADD;
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T> Matrix<M,N,T>::fiction(T f(T)){
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			Data[i][j]=f(Data[i][j]);
	return *this; 
}
Matrix<35,35,int> K,E,Q[64];
Matrix<35,1,int> I;
long long n,m,k;
Matrix<35,35,int> qpow(long long n){
    Matrix<35,35,int> T=E;
    for(int i=0;i<=60;i++)
        if((n>>i)&1ll)
            T=T*Q[i];
    return T;
}
int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    K.n=(1<<m);K.m=(1<<m);
    E.n=(1<<m);E.m=(1<<m);
    I.n=1;I.m=(1<<m);
    for(int i=0;i<=63;i++)
        Q[i].n=Q[i].m=(1<<m);
    for(int i=0;i<(1<<m);i++)
        E.Data[i][i]=1;
    for(int i=0;i<(1<<m);i++){
            if(__builtin_popcount(((i<<1)&((1<<m)-1)))<=k)K.Data[((i<<1)&((1<<m)-1))][i]=1;
            if(__builtin_popcount(((i<<1)&((1<<m)-1))|1)<=k)
                K.Data[((i<<1)&((1<<m)-1))|1][i]=1;
        }
    //K=E+K;
    Q[0]=K;
    for(int i=1;i<=60;i++) 
        Q[i]=Q[i-1]*Q[i-1];
    int ans=0;
    Matrix<35,35,int> T=qpow(n);
    // for(int i=0;i<(1<<m);i++)
    //     if(__builtin_popcount(i)<=k){
    //         I.Data[i][0]=1;
    //         I=T*I;
    //         (ans+=I.Data[i][0])%=p;
    //         I.Data[i][0]=0;
    //     }

    for(int i=0;i<(1<<m);i++)
        (ans+=T.Data[i][i])%=p;
    printf("%d\n",ans);
}