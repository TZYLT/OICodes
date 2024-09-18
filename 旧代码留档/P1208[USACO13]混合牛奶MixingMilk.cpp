#include<bits/stdc++.h>
using namespace std;
#define M 2002000
int n,m,ans;
pair<int,int> mi[M];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&mi[i].first,&mi[i].second);
	sort(mi+1,mi+1+m);
	for(int i=1;i<=n;i++){
		if(n>mi[i].second){
			n-=mi[i].second;
			ans+=mi[i].first*mi[i].second;
		}else{
			ans+=mi[i].first*n;
			break;
		}
	}
	printf("%d\n",ans);
}
