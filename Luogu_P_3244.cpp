#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define p 1000000007

struct edge{
	int v,next;
}e[M<<1];
int tot,head[M];
long long in[M];
void add(int u,int v){
	e[++tot].v =v;
	e[tot].next =head[u];
	head[u]=tot;
	in[u]+=1;
}
int n,m,xx,yy;
long long ans,cnt;
bool vis[M];
long long f[M];
long long qpow(long long a,long long b){
	long long c=1;
	while(b){
		if(b&1)c=(a*c)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return c;
}
void dfs(int u){
	if(u==yy)return ; 
	if(vis[u])return ;
	vis[u]=true;
	for(int i=head[u];i;i=e[i].next ){
		int v=e[i].v ;
		dfs(v);
		f[u]+=(f[v]*qpow(in[u],p-2)%p)%p;
		f[u]%=p;
	}
	return ;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&xx,&yy);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(v,u);
	}
	ans=1;cnt=1;in[1]=1;
	for(int i=1;i<=n;i++){
		ans=(ans*in[i])%p;
		if(i==yy)cnt=(cnt*(in[i]+1))%p;
		else cnt=(cnt*in[i])%p;
	}
	f[yy]=(ans*qpow(in[yy],p-2))%p;
	f[yy]%=p;
	dfs(xx);
	cnt=(cnt-f[xx]+p)%p;
	if(yy==1||xx==yy)printf("%lld\n",ans);
	else printf("%lld\n",cnt);
	return 0;
}