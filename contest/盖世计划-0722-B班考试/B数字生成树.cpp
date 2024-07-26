#include<bits/stdc++.h>
using namespace std;
#define M 100100
struct ed{
    int x,y,z;
}e[M];
int cnt;int n,m,q;
int ans,v[M],tr[M];
void prim(void){
    memset(v,0,sizeof(v));
    ans=0;
    v[1]=1;
    for(int i=1;i<n;i++){
        int minx,x=0;
        for(int j=1;j<=m*2;j++)
            if(v[e[j].x]==1&&v[e[j].y]==0)
                if(x==0||minx>(ans|e[j].z))
                    x=j,minx=ans|e[j].z;
        ans=minx;
        tr[x]=1;
        v[e[x].y]=1;
        //printf("[%d]:%d->%d\n",ans,e[x].x,e[x].y);
    }
}


int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        e[++cnt]={x,y,z};
        e[++cnt]={y,x,z};
    }m++;
    while(q--){
        
        int x,y;
        scanf("%d%d",&x,&y);
        e[cnt+1]={x,y,0};
        e[cnt+2]={y,x,0};
        prim();
        printf("%d\n",ans);
    }


}