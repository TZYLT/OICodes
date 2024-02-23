#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int a[1001000],n,ans[1001000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=1919810;
	s.push(0);
	for(int i=n;i>=1;i--){
		if(s.size())
			while(a[s.top()]<=a[i])
				s.pop();
		ans[i]=s.top();
		s.push(i);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}
