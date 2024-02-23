#include<bits/stdc++.h>
using namespace std;
int n,r;
vector<int> ans;
void dfs(int k){
	//if(ans.size()>0)printf("[%d:%d]",k,ans[ans.size()-1]);
	if(k==r+1) {
		for(auto u:ans) {
			printf("%3d",u);
		}
		putchar('\n');
		return;
	}
	else if(ans.size()>0)
		for(int i=ans[ans.size()-1]+1;i<=n;i++) {
		ans.push_back(i);
		dfs(k+1);
		ans.pop_back();
	}else for(int i=1;i<=n;i++) {
			ans.push_back(i);
			dfs(k+1);
			ans.pop_back();
	}
}
int main(){
	scanf("%d%d",&n,&r);
	dfs(1);
}
