#include<bits/stdc++.h>
using namespace std;
#define M 300300
vector<pair<int,int> > edge,dot;
long long hsh[M],bel[M];
int tag[M],ans[M],sum=1,cnt=1;
vector<int> st[M];
bool used[M];
int n,m;
int main(){
	srand(time(0));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		edge.push_back(make_pair(x,y));
	}
	for(int i=1;i<=n;i++)
		hsh[i]=1ll*rand()*rand()*rand();
	for(auto c:edge)
		bel[c.first]^=hsh[c.second],
		bel[c.second]^=hsh[c.first];
	for(int i=1;i<=n;i++)
		dot.push_back(make_pair(bel[i],i));
	sort(dot.begin(),dot.end());
	for(int i=0;i<n;i++){
		tag[dot[i].second]=cnt;
		if(dot[i].first!=dot[i+1].first)
			cnt++;
	}
	for(auto c:edge)
		if(bel[c.first]!=bel[c.second]&&tag[])
			
} 
