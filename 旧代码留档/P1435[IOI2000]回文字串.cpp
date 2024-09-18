#include<bits/stdc++.h>
using namespace std;
int f[1010][1010];
string s;
int main(){
	cin>>s;
	s=' '+s;
	int n=s.size()-1;
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			if(i==j)f[i][j]=0;
			else if(s[i]==s[j])
				f[i][j]=f[i+1][j-1];
			else f[i][j]=min(f[i][j-1],f[i+1][j])+1;
		}
	printf("%d\n",f[1][n]);
}
