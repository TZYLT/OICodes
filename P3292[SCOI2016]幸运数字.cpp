#include<bits/stdc++.h>
using namespace std;

int head[50050],nextt[50050],ver[50050],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
struct line{
    int data[65];
    void add(int x){
        for(int i=62;i;i--)
            if((x>>i)&1){
                if(!data[i])return b[i]=x,void();
                else x^=b[i];
            }
    }
    void merge(line x){
        for(auto c:x.data)
            if(!c)add(c);
    }
};

line f[20020][15];
int a[20020],fa[20020][15];
void dfs(int x,int ff){
    fa[x][0]=ff;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dfs(ver[i],x);
}
int n,q;
int main(){
    scanf("%d%d",&n,&q)
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=14;i++)
        for(int j=1;j<=n;j++)
            fa[j][i]=fa[fa[i][j-1]][j-1];
    for(int i=1;i<=14;i++)
        for(int j=1;j<=n;j++){
            f[j][i]=f[j][i-1];
            f[j][i].merge(f[fa[fa[j][i-1]][0]][i-1]);
        }
    
            
}

