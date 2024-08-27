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
int f[M][2];
void dfs(int x,int fa){
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs(ver[i],x);
            f[x][0]+=f[ver[i]][1];
            f[x][1]+=min(f[ver[i]][0],f[ver[i]][1]);
        }
    f[x][1]++;
}
int n,tot;
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(head,0,sizeof head);
        memset(f,0,sizeof f);
        memset(ver,0,sizeof ver);
        memset(nextt,0,sizeof nextt);
        cnt=0;
        for(int i=1;i<=n;i++){
            int x,y,k;
            scanf("%d:(%d)",&x,&k);
            for(int j=1;j<=k;j++)
                scanf("%d",&y),add(x+1,y+1),add(y+1,x+1);
        }
        dfs(1,0);
        printf("%d\n",min(f[1][0],f[1][1]));
    }
}