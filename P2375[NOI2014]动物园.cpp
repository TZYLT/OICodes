#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+3,MOD=1e9+7;
int N[MAXN],A[MAXN],B[MAXN],n,ans;
char S[MAXN];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",S+1),n=strlen(S+1),ans=1;
		for(int i=1;i<=n;++i){
			int p=N[i-1];
			while(p!=0&&S[p+1]!=S[i]) p=N[p];
			if(p+1<i&&S[p+1]==S[i]) ++p;
			N[i]=p,B[i]=B[N[i]]+1;
		}
		for(int i=1;i<=n;++i){
			int p=A[i-1];
			while(p!=0&&S[p+1]!=S[i])p=N[p];
			if(p+1<i&&S[p+1]==S[i])++p;
			while(p*2>i)p=N[p];
			A[i]=p;
			ans=1ll*ans*(B[A[i]]+1)%MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}
