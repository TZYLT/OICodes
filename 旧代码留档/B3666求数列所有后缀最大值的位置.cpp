#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000100];
deque<int> q;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-k+1;i++){
		if(q.empty())
			while(q.front()>a[i]){
				q.pop_front();
				if(q.empty())break;
			}
		q.push_front(a[i]);
		printf("%d ",q.back());
	}
	
}
