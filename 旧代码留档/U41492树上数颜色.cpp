#include<bits/stdc++.h>
using namespace std;

int head[200200],nextt[200200],ver[200200],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
set<int> s[100100];
int ans[100100];
int w[100100];
void dfs(int x,int fa){
    s[x].insert(w[x]);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs(ver[i],x);
            if(s[x].size()<s[ver[i]].size())
                swap(s[x],s[ver[i]]);
            for(auto c:s[ver[i]])
                s[x].insert(c);
            s[ver[i]].clear();
        }
    ans[x]=s[x].size();
}
int n,m;
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),add(x,y),add(y,x);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    dfs(1,0);
    scanf("%d",&m);
    while(m--){
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
}