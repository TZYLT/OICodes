#include<bits/stdc++.h>
using namespace std;
int n,m,q,T;
pair<int,int> h[100005],s[100005];
int main(){
	scanf("%d",&T); 
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=0;i<=n;i++)h[i]={0,0};
		for(int i=0;i<=m;i++)s[i]={0,0};
		for(int i=1;i<=q;++i){
			int o,x,c;
			cin>>o>>x>>c;
			if(o==0)h[x]={c,i};
			else s[x]={c,i};
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(h[i].second>s[j].second) cout<<h[i].first<<" ";
				else cout<<s[j].first<<" ";
			}
            putchar('\n');
		}
	}
	return 0;
}