#include<bits/stdc++.h>
using namespace std;
#define M 1000200
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int low[M],dfn[M],st[M],h,tot,c;
int v[M];
void dfs(int x){
    low[x]=dfn[x]=++tot;
    st[++h]=x;
    for(int i=head[x];i;i=nextt[i]){
        if(!dfn[ver[i]]){
            dfs(ver[i]);
            low[x]=min(low[x],low[ver[i]]);
        }else 
            if(!v[ver[i]])
                low[x]=min(low[x],dfn[ver[i]]);
    }
    if(dfn[x]==low[x]){
        ++c;
        while(st[h]!=x)
            v[st[h--]]=c;
        v[x]=c;h--;
    }
}
int n,m;
int in[M],out[M];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        while(1){
            int x;
            scanf("%d",&x);
            if(x==0)break;
            add(i,x);
        }
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i);
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=nextt[j])
            if(v[ver[j]]!=v[i])
                in[v[ver[j]]]++,out[v[i]]++;
    if(c==1){
        printf("1\n0\n");
        return 0;
        
    }
    int ansl=0,ansr=0;
    for(int i=1;i<=c;i++)
        ansl+=(in[i]==0);
    for(int i=1;i<=c;i++)
        ansr+=(out[i]==0);
    
    printf("%d\n%d\n",ansl,max(ansl,ansr));
}