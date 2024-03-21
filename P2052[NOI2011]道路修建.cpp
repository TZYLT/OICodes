#include<bits/stdc++.h>
using namespace std;
#define M 3001000
int head[M],nextt[M],edge[M],_size[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int uv[M];
void dfs(int x,int fa,int v){
    _size[x]=1;uv[x]=v;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs(ver[i],x,i);
            _size[x]+=_size[ver[i]];
    }
}
int n;long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        ans+=(long long)edge[uv[i]]*abs(n-_size[i]-_size[i]);
    }
    printf("%lld\n",ans);
}