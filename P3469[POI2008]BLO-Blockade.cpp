#include<bits/stdc++.h>
using namespace std;
#define M 1000100
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
long long a[M];
int dfn[M],low[M],cut[M],c,id;
int st[M],h;
vector<int> ans[M];
int _size[M];
int n,m;
void dfs(int x,int fa){
    dfn[x]=low[x]=++id;
    int sum=0;
    st[++h]=x;_size[x]=1;
    int son=0;
    for(int i=head[x];i;i=nextt[i]){
        if(ver[i]!=fa){
            if(dfn[ver[i]]==0){
                ++son;
                dfs(ver[i],x);
                low[x]=min(low[x],low[ver[i]]);
                _size[x]+=_size[ver[i]];
                if(low[ver[i]]>=dfn[x]){
                    sum+=_size[ver[i]];
                    a[x]+=1ll*_size[ver[i]]*(n-_size[ver[i]]);
                    cut[x]=1;
                    ++c;
                    while(st[h]!=ver[i]){
                        ans[c].push_back(st[h]);
                        h--;
                    }
                    ans[c].push_back(ver[i]);
                    h--;
                    ans[c].push_back(x);
                }
            }
            else low[x]=min(low[x],dfn[ver[i]]);
        }   
    } 
    if(son==0&&fa==0)ans[++c].push_back(x);
    if(cut[x]==1)a[x]+=1ll*(n-sum-1)*(sum+1)+n-1;
    else a[x]=2*(n-1);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)
        scanf("%d%d",&x,&y),add(x,y),add(y,x);
    for(int i=1;i<=n;i++)
        if(dfn[i]==0)
            dfs(i,0);
    for(int i=1;i<=n;i++)
        printf("%lld\n",a[i]);
}