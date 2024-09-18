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
				ADD.Data[i][k]=(1ll*ADD.Data[i][k]+1ll*Data[i][j]*in.Data[j][k]%p)%p;
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

Matrix<3,3,int> ans,A[40],B,E;
Matrix<3,1,int> aa;
Matrix<3,3,int> qp(int n){
	Matrix<3,3,int> res=E;
	int t=0;
	while(n){
		if(n&1) res=res*A[t];
		n>>=1;t++;
	}
	return res;
	
}

int n,m;
int a[100100];
int main(){
    A[0].Data[0][0]=1;A[0].Data[0][1]=0;A[0].Data[0][2]=1;
    A[0].Data[1][0]=2;A[0].Data[1][1]=1;A[0].Data[1][2]=2;
    A[0].Data[2][0]=1;A[0].Data[2][1]=1;A[0].Data[2][2]=2;

	aa.Data[0][0]=1;aa.Data[1][0]=0;aa.Data[2][0]=0;

    B.Data[0][0]=1;B.Data[0][1]=0;B.Data[0][2]=0;
    B.Data[1][0]=2;B.Data[1][1]=1;B.Data[1][2]=0;
    B.Data[2][0]=1;B.Data[2][1]=1;B.Data[2][2]=1;

    E.Data[0][0]=1;E.Data[0][1]=0;E.Data[0][2]=0;
    E.Data[1][0]=0;E.Data[1][1]=1;E.Data[1][2]=0;
    E.Data[2][0]=0;E.Data[2][1]=0;E.Data[2][2]=1;

    for(int i=1;i<=35;i++)
        A[i]=A[i-1]*A[i-1];
    

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",a+i);
    a[0]=-1;
	ans=E;
    for(int i=1;i<=m;i++){
		ans=qp(a[i]-a[i-1]-1)*ans;
		ans=B*ans;
	}
	ans=qp(n-a[m]-1)*ans;

	aa=ans*aa;

	printf("%d\n",aa.Data[2][0]);
}