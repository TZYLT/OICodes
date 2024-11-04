#include<bits/stdc++.h>
using namespace std;
int dp[200200][45];
int ls[200200][45];
int a[200200];
int tp[200200];
int n,m,c,d,ns;
int q[200200],h,t;
void dfs(int i,int j){
    if(!j)return;
    dfs(ls[i][j],j-1);
    printf("%d ",ls[i][j]+1);
}
int main(){
    scanf("%d%d%d%d",&n,&m,&c,&d);
    ns=n*c+m;
    for(int i=1;i<=ns;i++)
        scanf("%d",a+i),a[i]+=a[i-1];
    memset(dp,0xcf,sizeof(dp));
	for(int i=1;i<=d;i++)
		dp[i][0]=a[i];
	
    for(int j=1;j<=n;j++){
        h=0;t=1;
        for(int i=0;i<=ns;i++)
            tp[i]=dp[i][j-1]+(a[i+1]-a[i])-a[i+c];
        for(int i=c;i<=ns;i++){
            while(h-t+1>0&&q[t]<i-c-d)t++;
            while(h-t+1>0&&tp[q[h]]<tp[i-c])h--;
            q[++h]=i-c;
            dp[i][j]=tp[q[t]]+a[i];
            ls[i][j]=q[t];
        }
    }
    printf("%d\n",dp[ns][n]);
    dfs(ns,n);
}