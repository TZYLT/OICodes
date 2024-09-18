#include<bits/stdc++.h>
using namespace std;
#define M 400100
int block,n,m,k,ans[M],attack[M],tot,head[M],ver[M],nextt[M];
void add(int x,int y){
	tot++;
	ver[tot]=y;
	nextt[tot]=head[x];
	head[x]=tot;
}
int fa[M],v[M];
void init(void){
	for(int i=1;i<=n;i++) fa[i]=i;
	block=n;
}
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	if(get(x)==get(y)) return;
	fa[get(x)]=get(y);
	block--;
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x+1,y+1);
		add(y+1,x+1);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&attack[i]),v[attack[i]+=1]=1,block--;
	for(int i=1;i<=n;i++)
		if(!v[i])
			for(int j=head[i];j;j=nextt[j])
				if(!v[ver[j]])
					merge(i,ver[j]);
	ans[0]=block;
	
	for(int i=k;i>=1;i--){
		block++;v[attack[i]]=0;
		for(int j=head[attack[i]];j;j=nextt[j])
			if(!v[ver[j]])
				merge(attack[i],ver[j]);
		ans[k-i+1]=block;
	}
	for(int i=k;i>=0;i--)
		printf("%d\n",ans[i]);
}
