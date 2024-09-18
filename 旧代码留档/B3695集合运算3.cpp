#include<bits/stdc++.h>
using namespace std;
bitset<30500> s[30500],out;
int n,m,q;
int o,x,y;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	out.reset();
	for(int i=0;i<m;i++)
		out.set(i,1);
	
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int t;
			scanf("%d",&t);
			s[i].set(t-1,1);
		}
		
	}
	
	while(q--){
		scanf("%d%d%d",&o,&x,&y);
		if(o==1){
			s[x]<<=y;
			s[x]&=out;
		}
		else if(o==2){
			s[x]>>=y;
			s[x]&=out;
		}else if(o==3){
			bitset<30500> t;
			t=s[x]&s[y];
			printf("%d\n",t.count());
		}else if(o==4){
			bitset<30500> t;
			t=s[x]|s[y];
			printf("%d\n",t.count());
		}else if(o==5){
			bitset<30500> t;
			t=s[x]^s[y];
			printf("%d\n",t.count());
		}
	}
}
