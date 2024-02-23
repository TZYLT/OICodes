#include<bits/stdc++.h>
using namespace std;
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
		Matrix operator=(Matrix<M,N,T> in);
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
T& Matrix<M,N,T>::readData(unsigned m,unsigned n){
	return Data[m-1][n-1];
}

template <unsigned M,unsigned N,class T>
int Matrix<M,N,T>::readh(void){
	return n;
}

template <unsigned M,unsigned N,class T>
int Matrix<M,N,T>::readl(void){
	return m;
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T> Matrix<M,N,T>::operator+(Matrix<M,N,T> in){
	Matrix<M,N,T> ADD;
	ADD.setClear();
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			ADD.Data[i][j]=Data[i][j]+in.Data[i][j];
	return ADD;
}

template <unsigned M,unsigned N,class T>
	template <unsigned P>
Matrix<M,P,T> Matrix<M,N,T>::operator*(Matrix<N,P,T> in){
	Matrix<M,P,T> ADD;
	ADD.setClear();
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<P;k++)
				ADD.Data[i][k]=((long long)ADD.Data[i][k]+(long long)Data[i][j] * in.Data[j][k])%1000000007;
	return ADD;
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T> Matrix<M,N,T>::operator*(T in){
	Matrix<M,N,T> ADD;
	ADD.setClear();
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			ADD.Data[i][j]=Data[i][j]*in;
	return ADD;
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T> Matrix<M,N,T>::operator=(Matrix<M,N,T> in){
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			Data[i][j]=in.Data[i][j];
	return *this; 
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T> Matrix<M,N,T>::fiction(T f(T)){
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			Data[i][j]=f(Data[i][j]);
	return *this; 
}
int T,n;
Matrix<3,3,int> a,ans,k[32];
Matrix<3,1,int> t;
int main(){
	a.Data[0][0]=1;a.Data[0][1]=0;a.Data[0][2]=1;
	a.Data[1][0]=1;a.Data[1][1]=0;a.Data[1][2]=0;
	a.Data[2][0]=0;a.Data[2][1]=1;a.Data[2][2]=0;
	t.Data[0][0]=1;t.Data[1][0]=1;t.Data[2][0]=1;
	ans.Data[0][0]=1;ans.Data[0][1]=0;ans.Data[0][2]=0;
	ans.Data[1][0]=0;ans.Data[1][1]=1;ans.Data[1][2]=0;
	ans.Data[2][0]=0;ans.Data[2][1]=0;ans.Data[2][2]=1;
	k[0]=a;
	for(int i=1;i<=31;i++)
		k[i]=k[i-1]*k[i-1];
	
	scanf("%d",&T);
	while(T--){
		Matrix<3,3,int> ansn=ans;
		scanf("%d",&n);
		if(n<=3){printf("%d\n",1);continue;}
		n-=3;
		for(int i=0;i<=30;i++)
			if(n&(1<<i)){
				ansn=k[i]*ansn;
			}
		Matrix<3,1,int> te;
		te=ansn*t;
			
		printf("%d\n",te.Data[0][0]);
	}	
			
}
