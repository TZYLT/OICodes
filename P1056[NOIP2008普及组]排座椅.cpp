#include<bits/stdc++.h>
using namespace std;
int m,n,k,l,d;
pair<int,int> d1,d2,x[1010],y[1010];
vector<int> ans1,ans2;
int main(){
	scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
	for(int i=1;i<=1005;i++)
		x[i].second=y[i].second=i;
	for(int i=1;i<=d;i++){
		scanf("%d%d%d%d",&d1.first,&d1.second,&d2.first,&d2.second);
		if(d1.first==d2.first){
			x[min(d1.second,d2.second)].first++;
		}
		if(d1.second==d2.second){
			y[min(d1.first,d2.first)].first++;
		}
	}
	sort(x+1,x+1001);
	sort(y+1,y+1001);
	for(int i=1;i<=k;i++)
		ans1.push_back(y[1001-i].second);
	for(int i=1;i<=l;i++)
		ans2.push_back(x[1001-i].second);
	
	sort(ans1.begin(),ans1.end());
	sort(ans2.begin(),ans2.end());
	
	for(auto u:ans1)
		printf("%d ",u);	
		putchar('\n');
	for(auto u:ans2)
		printf("%d ",u);
		putchar('\n');
}

