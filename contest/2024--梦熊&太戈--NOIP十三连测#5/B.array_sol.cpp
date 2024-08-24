#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int l[505],r[505],ans=0;
int dp[505],n,maxx=0;
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
Matrix<M,N,T> Matrix<M,N,T>::operator+(Matrix<M,N,T> in){
	Matrix<M,N,T> ADD;
	ADD.setClear();
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			ADD.Data[i][j]=Data[i][j]+in.Data[i][j];
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
				ADD.Data[i][k]=((long long)ADD.Data[i][k]+(long long)Data[i][j]*in.Data[j][k])%p;
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
vector<int> opt[1010];
vector<int> id;
Matrix<500,500,int> a,b;
Matrix<500,1,int> st;
int s[505]; 
int main(){
    freopen("array.in","r",stdin);
    freopen("array.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",l+i,r+i);
        maxx=max(maxx,r[i]);
        id.push_back(l[i]-1);
        id.push_back(r[i]);
    }
    sort(id.begin(),id.end());
    unique(id.begin(),id.end());
    for(int i=1;i<=n;i++){
        int il=lower_bound(id.begin(),id.end(),l[i]-1)-id.begin();
        opt[il].push_back(-i);
        int ir=lower_bound(id.begin(),id.end(),r[i])-id.begin();
        opt[ir].push_back(i);
    }
    st.Data[0][0]=1;
    st.m=n+1;
    a.n=n+1;b.n=n+1;
    a.m=n+1;b.m=n+1;

    for(int i=id.size()-1;i>=0;i--){
        for(auto c:opt[i])
            s[abs(c)]=(c>0?1:0);
        a.setClear();
        a.Data[0][0]=1;
        for(int j=1;j<=n;j++){
            a.Data[j][j]=1;
            if(s[j])
                for(int k=0;k<=n;k++)
                    a.Data[j][k]+=a.Data[j-1][k];
        }
        
        b.setClear();
        for(int j=0;j<=n;j++)
            b.Data[j][j]=1;
        int k=id[i]-id[i-1];
		while(k>0){
			if(k&1) b=b*a;
			a=a*a;
			k>>=1;
		}
        st=b*st;
    }
    printf("%d\n",st.Data[n][0]);
}
