#include<bits/stdc++.h>
using namespace std;
int n;
int _size[100100],f[100100];

int head[100100],nextt[100100],ver[100100],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int ans,mf=(1<<20);
void dfsI(int x,int fa){
    _size[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dfsI(ver[i],x),_size[x]+=_size[ver[i]];
    f[x]=n-_size[x];
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            f[x]=max(_size[ver[i]],f[x]);
    if(mf>=f[x])mf=f[x],ans=x;
}

int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfsI(1,0);
    for(int i=1;i<=n;i++)
        printf("%d",f[i]);
        
}
