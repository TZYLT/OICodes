#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],i=0,j=0,sum,mmax=-(1<<30),k=1;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(i<=n){
		i++;
		sum+=a[i];
		if(sum<0)j=i,sum=0;
		while(i-j>m)j++,sum-=a[j];
		mmax=max(mmax,sum);
	}
	cout<<mmax<<endl;
}