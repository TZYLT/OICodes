# include <bits/stdc++.h>
using namespace std;
long long f[15][15];
int a[15];
long long sol(long long x){
	int len=0;
	while(x>0ll)a[++len]=x%10,x/=10;
	long long sum=0ll;
	for(int i=1;i<=len-1;i++)
	    for(int j=1;j<=9;j++)
	        sum+=f[i][j];
	for(int i=1;i<a[len];i++) 
        sum+=f[len][i];
	for(int i=len-1;i>=1;i--){
		for(int j=0;j<=a[i]-1;j++)
		    if(abs(j-a[i+1])>=2)
                sum+=f[i][j];
		if(abs(a[i+1]-a[i])<2)break;
	}
	return sum;
}
int main(){
	long long n,m;
    scanf("%lld %lld",&n,&m);
	if(n>m)swap(n,m);
	for(int i=0;i<=9;i++)
        f[1][i]=1ll;
	for(int i=2;i<=10;i++)
	    for(int j=0;j<=9;j++)
	        for(int k=0;k<=9;k++)
	            if(abs(k-j)>=2)
                    f[i][j]+=f[i-1][k];
	printf("%lld\n",sol(m+1)-sol(n));
}