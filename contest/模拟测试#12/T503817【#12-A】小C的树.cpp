#include<bits/stdc++.h>
using namespace std;
#define M 1000500
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int w[M],in[M];
int dp[M];
vector<int> st;
int t,n;
void dfs(int x,int fa){
    if(in[x]==0)return dp[x]=1,void();
    if(w[x]==1){
        dp[x]=0x7f7f7f7f;
        for(int i=head[x];i;i=nextt[i])
            if(ver[i]!=fa)
                dfs(ver[i],x),dp[x]=min(dp[x],dp[ver[i]]);
    }if(w[x]==0){
        dp[x]=0;
        for(int i=head[x];i;i=nextt[i])
            if(ver[i]!=fa)
                dfs(ver[i],x),dp[x]+=dp[ver[i]];
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=2;i<=n;i++){
            int x;
            scanf("%d",&x);
            add(x,i);
            add(i,x);
            in[x]=1;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",w+i);
            if(in[i]==0)st.push_back(w[i]);
        }
        dfs(1,0);
        sort(st.begin(),st.end());
        printf("%d\n",st[st.size()-dp[1]]);

        for(int i=0;i<=cnt;i++)
            head[i]=ver[i]=nextt[i]=0;
        cnt=0;
        st.clear();
        for(int i=0;i<=n;i++)
            w[i]=dp[i]=in[i]=0;
    }
}