#include<bits/stdc++.h>
using namespace std;
int n,t;
int f[25050],g[25050];
int v[10010],c[10010];
int main(){
    memset(f,0x1f,sizeof f);
    memset(g,0x1f,sizeof g);
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
        scanf("%d",v+i);
    for(int i=1;i<=n;i++)
        scanf("%d",c+i);
    f[0]=g[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=25000;j++)
            f[j]=min(f[j],f[j-v[i]]+1);
    for(int i=1;i<=n;i++){
        vector<pair<int,int> > it;
        for(int j=1;j<=c[i];j<<=1)
            it.push_back({v[i]*j,j}),c[i]-=j;
        for(auto tt:it)
            for(int j=25000;j>=tt.first;j--)
                g[j]=min(g[j],g[j-tt.first]+tt.second);
    }
    int ans=0x7f7f7f7f;
    for(int i=t;i<=25000;i++)
        ans=min(ans,g[i]+f[i-t]);
    if(ans<=10000000)printf("%d\n",ans);
    else printf("-1");
        
    
}