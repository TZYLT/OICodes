#include<bits/stdc++.h>
using namespace std;
struct node {int tim,mny;} w[100001];
int n,i;
long long ans;
priority_queue<int,vector<int>,greater<int> > q;
bool cmp(node a,node b){return a.tim<b.tim;}
int main() {
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		scanf("%d%d",&w[i].tim,&w[i].mny);
	sort(w+1,w+n+1,cmp);
	for (i=1; i<=n; i++) {
		if (w[i].tim<=q.size()) {
			if (w[i].mny>q.top()) {
				ans-=q.top();
				q.pop();
				q.push(w[i].mny);
				ans+=w[i].mny;
			}
		} else {
			q.push(w[i].mny);
			ans+=w[i].mny;
		}
	}
	printf("%lld",ans);
	return 0;
}
