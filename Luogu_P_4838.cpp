#include<bits/stdc++.h>
using namespace std;
#define p 19260817
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
Matrix<M,N,T>& Matrix<M,N,T>::setAllData(T inData){
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			Data[i][j]=inData;	
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T> Matrix<M,N,T>::operator+(Matrix<M,N,T> in){
	Matrix<M,N,T> ADD;
	ADD.setClear();
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			ADD.Data[i][j]=(Data[i][j]+in.Data[i][j])%p;
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
				ADD.Data[i][k]=(ADD.Data[i][k]+1ll*Data[i][j]*in.Data[j][k]%p)%p;
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
Matrix<3,3,int> E,T[101];
int t,n; 
int main(){
    scanf("%d",&t);
    E.Data[0][0]=1;E.Data[0][1]=0;E.Data[0][2]=0;
    E.Data[1][0]=0;E.Data[1][1]=1;E.Data[1][2]=0;
    E.Data[2][0]=0;E.Data[2][1]=0;E.Data[2][2]=1;
    T[0].Data[0][0]=1;T[0].Data[0][1]=1;T[0].Data[0][2]=1;
    T[0].Data[1][0]=1;T[0].Data[1][1]=0;T[0].Data[1][2]=0;
    T[0].Data[2][0]=0;T[0].Data[2][1]=1;T[0].Data[2][2]=0;
    for(int i=1;i<=60;i++)
        T[i]=T[i-1]*T[i-1];
    
    while(t--){
        scanf("%d",&n);
        Matrix<3,3,int> A;
        A=E;
        for(int i=30;i>=0;i--)
            if((n>>i)&1)A=A*T[i];

        printf("%d\n",(A.Data[0][0]+A.Data[1][0]+A.Data[2][0])%p);
    }
}