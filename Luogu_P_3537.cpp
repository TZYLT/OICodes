#include<bits/stdc++.h>
using namespace std;
struct qs{
    int id,k,s;
};
vector<qs> q[2010];
int ans[1001000];
struct item{
    int a,b,c;
    friend bool operator<(item x,item y){
        return x.a<y.a;
    }
}it[2010];
int n,m;
int dp[200100],mt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&it[i].c,&it[i].a,&it[i].b);
    sort(it+1,it+1+n);
    scanf("%d",&m);
    it[n+1]={0x3f3f3f3f,0,0};
    for(int i=1;i<=m;i++){
        int a,b,c;//m k s
        scanf("%d%d%d",&a,&b,&c);
        int id=upper_bound(it+1,it+2+n,(item){a,0,0})-it;
        while(it[id].a>a)id--;
        //printf("%d\n",id);
        q[id].push_back({i,b,a+c});
        mt=max(mt,b);
    }
    memset(dp,0,sizeof dp);
    dp[0]=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        for(int j=mt;j>=it[i].c;j--)
            dp[j]=max(dp[j],min(dp[j-it[i].c],it[i].b));
        // for(int j=0;j<=mt;j++)
        //     printf("%d ",dp[j]);
        // puts("");
        for(qs c:q[i])
            ans[c.id]=(dp[c.k]>c.s);
    }
    for(int i=1;i<=m;i++)
        printf(ans[i]?"TAK\n":"NIE\n");
}
