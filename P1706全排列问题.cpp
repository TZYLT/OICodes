#include<bits/stdc++.h>
using namespace std;
int n;bool a[10];
vector<int> ans;
void dfs(int k){
	if(k==n+1) {
		for(auto u:ans) 
			printf("%5d",u);
		putchar('\n');
		return;
	}
	for(int i=1;i<=n;i++)
		if(!a[i]){
			ans.push_back(i);
			a[i]=1;
			dfs(k+1);
			ans.pop_back();
			a[i]=0;
		}
}
int main(){
	scanf("%d",&n);
	dfs(1);
}
