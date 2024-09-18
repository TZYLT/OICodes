#include<bits/stdc++.h>
using namespace std;
const int p[2]={233,367};
const int q[2]={12255871,1000000009};
int Hash(string &s,int k){
	int t=1,h=0;
	for(int i=s.size()-1;i>=0;i--){
		h=(h+(long long)s[i]*t%q[k])%q[k];
		t=(long long)t*p[k]%q[k];
	}
	return h;
}

int n;

pair<int,int> a[10010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string in;
		cin>>in;
		a[i]=make_pair(Hash(in,0),Hash(in,1));
	}
	sort(a+1,a+n+1);
	printf("%d\n",unique(a+1,a+1+n)-a-1);
}
