#include<bits/stdc++.h>
using namespace std;
#define M 400200
set<int> s[M];
int head[M],nextt[M],ver[M],cnt;
int n,ans,a[M],dis[M];
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
void dfs(int x,int fa){
    bool t=0;
    s[x].insert(dis[x]);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dis[ver[i]]=a[ver[i]]^dis[x];
            dfs(ver[i],x);
            if(s[x].size()<s[ver[i]].size())
                swap(s[x],s[ver[i]]);
            for(int c:s[ver[i]])if(s[x].find(c^a[x])!=s[x].end())
                t=1;
            for(int c:s[ver[i]])s[x].insert(c);
        }
    if(t)ans++,s[x].clear();
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dis[1]=a[1];
    dfs(1,0);
    printf("%d\n",ans);

}