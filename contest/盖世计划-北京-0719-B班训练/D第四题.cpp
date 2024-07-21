#include<bits/stdc++.h>
using namespace std;
#define M 600600
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
long long ans,sum,f[M],n,a[M];
void dfs1(int x,int fa){
	f[x]=a[x];
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=fa)
			dfs1(ver[i],x),f[x]+=max(f[ver[i]],0ll);
	ans=max(ans,f[x]);
}
void dfs2(int x,int fa){
	f[x]=a[x];
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=fa)
			dfs2(ver[i],x),f[x]+=max(f[ver[i]],0ll);
	if(f[x]==ans)sum++,f[x]=0;
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    ans=-(1ll<<60);
    dfs1(1,0);
    memset(f,0,sizeof(f));
    dfs2(1,0);
    printf("%lld %lld\n",ans*sum,sum);
}
