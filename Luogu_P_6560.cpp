#include<bits/stdc++.h>
using namespace std;
#define M 501000
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int dp[M],in[M],kin[M];
int n,m,q;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(y,x);kin[x]++;
    }
    while(q--){
        int s,t;
        scanf("%d%d",&s,&t);
        memset(dp,0,sizeof dp);
        memcpy(in,kin,sizeof kin);
        queue<int> q;
        for(int i=1;i<=n;i++)
            if(!in[i]||i==t)
                q.push(i),dp[i]=-1;
        while(q.size()){
            int x=q.front();q.pop();
            for(int i=head[x];i;i=nextt[i])
                if(!dp[ver[i]]){
                    if(dp[x]==1){
                        in[ver[i]]--;
                        if(!in[ver[i]])
                            q.push(ver[i]),dp[ver[i]]=-1;
                    }else q.push(ver[i]),dp[ver[i]]=1;
                }
        }
        printf("%d\n",dp[s]);
    }
}