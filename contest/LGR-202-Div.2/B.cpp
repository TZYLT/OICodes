#include<bits/stdc++.h>
using namespace std;
#define M 500100
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
long long w[M];
int dfs(int x,int fa){
    if(!nextt[head[x]])return 1;
    long long sum=0;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            sum+=w[ver[i]];
    //printf("[%d]:%d\n",x,sum);        
    if(sum>w[x])return 0;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            if(!dfs(ver[i],x)||w[ver[i]]>w[x])return 0;
        }
    return 1;
}
int t,n,c;
int main(){
    freopen("water2.in","r",stdin);
    freopen("w.out","w",stdout);
    scanf("%d",&c);
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<=cnt+10;i++)
            ver[i]=nextt[i]=0;
        for(int i=0;i<=n+10;i++)
            w[i]=head[i]=0;
        cnt=0;n=0;
        scanf("%d",&n);
        for(int i=2,f;i<=n;i++)
            scanf("%d",&f),add(i,f),add(f,i);
        for(int i=1;i<=n;i++)
            w[i]=0;
        for(int i=1,x;i<=n;i++)
            scanf("%d",&x),w[i]+=x;
        if(dfs(1,0))printf("Huoyu\n");
        else printf("Shuiniao\n");
    }
}