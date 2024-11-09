#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e2+5;
const int INF=0x3f3f3f3f;
int n,a[N],b[N],cnt1,s,t,dep[N];
ll ans;
int id=1,h[N],cur[N],e[2*N*N],w[2*N*N],ne[2*N*N];
bool check(int x){
	for(int i=2;i*i<=x;i++){
		if(!(x%i)){
			return 0;
		}
	}
	return 1;
}
void add(int a,int b,int c){
	id++;
	ne[id]=h[a];
	h[a]=id;
	e[id]=b;
	w[id]=c;
}
bool bfs(){
	queue<int> que;
	memset(dep,0,sizeof(dep));
	dep[s]=1;
	que.push(s);
	while(que.size()){
		int p=que.front();
		que.pop();
		for(int i=h[p];i;i=ne[i]){
			if(w[i]&&!dep[e[i]]){
				dep[e[i]]=dep[p]+1;
				que.push(e[i]);
			}
		}
	}
	return dep[t];
}
ll dfs(int p,ll flow){
	ll res=0;
	if(p==t){
		res=flow;
	}else{
		for(int i=cur[p];i;i=ne[i]){
			cur[p]=i;
			if(w[i]&&dep[e[i]]==dep[p]+1){
				int v=dfs(e[i],min(flow,1ll*w[i]));
				w[i]-=v;
				w[i^1]+=v;
				res+=v;
				if(!(flow-=v)){
					break;
				}
			}
		}
	}
	return res;
}
ll Dinic(){
	ll res=0;
	while(bfs()){
		memcpy(cur,h,sizeof(h));
		res+=dfs(s,1ll*n*INF);
	}
	return res;
}
int main(){
	scanf("%d",&n);
	s=n+1;
	t=n+2;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]>1){
			if(a[i]&1){
				add(s,i,b[i]);
				add(i,s,0);
			}else{
				add(i,t,b[i]);
				add(t,i,0); 
			}
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(a[i]+a[j])){
				if(a[i]&1){
					add(i,j,INF);
					add(j,i,0);
				}else{
					add(j,i,INF);
					add(i,j,0);
				}	
			}
		}
	}
	ans=Dinic();
	for(int i=h[s];i;i=ne[i]){
		w[i]=w[i^1]=0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			add(s,i,b[i]);
			add(i,s,0);
			int v=Dinic();
			ans+=v+(b[i]-v)/2;
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}