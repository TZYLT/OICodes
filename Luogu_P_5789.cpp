#include<bits/stdc++.h>
using namespace std;
#define p 2017
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
			for(int k=0;k<in.n;k++)
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
Matrix<M,N,T> Matrix<M,N,T>::operator=(Matrix<M,N,T> in){
	n=in.n;m=in.m;
    for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			Data[i][j]=in.Data[i][j];
	return *this; 
}

template <unsigned M,unsigned N,class T>
Matrix<M,N,T> Matrix<M,N,T>::fiction(T f(T)){
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			Data[i][j]=f(Data[i][j]);
	return *this; 
}
int n,m,t;
//vector<pair<int,int> > eg;
Matrix<101,101,int> E,T;
int main(){
    scanf("%d%d",&n,&m);
    E.m=n+1;E.n=n+1;
    for(int i=0;i<=n;i++)
        E.Data[i][i]=1;
    
    for(int i=1;i<=n;i++)
        T.Data[i][i]++;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        T.Data[y][x]++;
        T.Data[x][y]++;
    }
    for(int i=0;i<=n;i++)
        T.Data[0][i]++;
    scanf("%d",&t);
    while(t){
        if(t&1)E=E*T;
        T=T*T;
        t>>=1;
    }
    int ans=0;
    for(int i=0;i<=n;i++)
        (ans+=E.Data[i][1])%=p;
    printf("%d\n",ans);
}
