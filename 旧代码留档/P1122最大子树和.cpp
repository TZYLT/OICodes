#include<bits/stdc++.h>
using namespace std;
#define M 200200
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int w[M],f[M],ans=0xcfcfcfcf;
void dp(int x,int fa){
    f[x]=w[x];
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dp(ver[i],x);
            f[x]+=max(f[ver[i]],0);
        }   
    ans=max(ans,f[x]);
}
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dp(1,0);
    printf("%d\n",ans);
}