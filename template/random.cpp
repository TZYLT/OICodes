#include<bits/stdc++.h>
using namespace std;
int random(int n){
	return (long long)(rand()*rand()+rand())%n;
}
int main(){
	srand(time(0));
	freopen("test1.in","w",stdout);
	int n=random(1000000);
	int g=random(1000000);
	int m=1000;
	printf("%d %d\n",n,g);
	for(int i=0;i<=n;i++){
		printf("%d ",random(2*m+1)-m/2);
	}
	cout<<endl;
	for(int i=0;i<=g;i++){
		
		int l=random(n)+1;
		int r=random(n)+1;
		if(l>r)swap(l,r);
		if(random(2))printf("%d %d %d\n",1,l,r);
		else printf("%d %d %d %d\n",0,l,r,random(m+1)-m/2);
	}
}
