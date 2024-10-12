#include<bits/stdc++.h>
using namespace std;
int f[100000],p[100000],k,m,n,s[100000],dp[100000],tot;
int find(int u){
	if(f[u]==u) return u;
	else return f[u]=find(f[u]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		f[i]=i,p[i]=1;
	for(int i=1;i<=k;i++){
        int x,y;
		scanf("%d%d",&x,&y);
		int u=find(x);int v=find(y);
		if(u!=v) f[u]=v,p[v]+=p[u];
	}
	for(int i=1;i<=n;i++)
	    if(f[i]==i)
		    s[++tot]=p[i];
	for(int i=1;i<=tot;i++)
		for(int j=2*m;j>=s[i];j--)
			dp[j]=max(dp[j],dp[j-s[i]]+s[i]);
	int ans=0x7f7f7f7f,minn=0x7f7f7f7f;
	for(int i=1;i<=2*m;i++)
		if(minn>abs(dp[i]-m)) 
            minn=abs(dp[i]-m),ans=dp[i];
	
	if(ans==0x7f7f7f7f) printf("0");
	else printf("%d",ans);
	return 0;
}