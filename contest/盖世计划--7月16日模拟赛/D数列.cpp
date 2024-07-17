#include<bits/stdc++.h>
using namespace std;
bitset<10000000> v;int n,k,t;
int main(){
	//freopen("array.in","r",stdin);
    //freopen("array.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int sum=0;int h=0,cnt=0;
		for(int i=1;i<=n;i++)v[i]=0;
		for(int i=1;i<=n;i++){
			if(v[i]==0){
				sum+=i;
				h++;
				v[i]=1;cnt++;
				if(i==n)printf("%d\n",cnt);
			}
			if(h==k){
				h=0;
				v[sum>n?0:sum]=1;cnt++;
				if(sum==n)printf("%d\n",cnt);
				sum=0;
			}
		}
	}
}
