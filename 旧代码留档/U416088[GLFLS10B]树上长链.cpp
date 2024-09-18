#include<bits/stdc++.h>
using namespace std;
#define M 2001000
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int v[M],d[M],f[M];
void dp(int x){
    v[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if(!v[ver[i]]){
            dp(ver[i]);
            d[x]=max(d[x],f[x]+f[ver[i]]+1);
            f[x]=max(f[x],f[ver[i]]+1);
        }
}
int n,y;
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d",&y);
        add(i,y);
        add(y,i);
    }
    dp(1);
    for(int i=1;i<=n;i++)
        printf("%d ",f[i]);
    
}