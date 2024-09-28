#include<bits/stdc++.h>
using namespace std;
#define M 10010
int n,m;
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int ans=0;
void dfs(int x,int fa,int d){
    ans=max(ans,d);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dfs(ver[i],x,d+1);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);x++;y++;
        add(x,y);add(y,x);
    }
    dfs(1,0,1);
    if(ans>=m+1)printf("%d\n",m+1);
    else printf("%d\n",min(n,ans+((m-ans+1)>>1)));
}