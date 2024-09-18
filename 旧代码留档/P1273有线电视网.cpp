#include<bits/stdc++.h>
using namespace std;
#define M 100100
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int dp[M][2];
void dfs(int x,int fa){
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dfs(ver[i],x);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
}
int main(){
    
}