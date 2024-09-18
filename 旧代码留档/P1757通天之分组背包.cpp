#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int> > st[200];
int a,b,c;
int f[150][1010];
int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<=110;i++) 
        st[i].push_back(make_pair(0,0));
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a,&b,&c),
        st[c].push_back(make_pair(a,b));
    
    for(int i=1;i<=110;i++)
        for(auto c:st[i])
            for(int j=m;j>=0;j--)
                if(j>=c.first)f[i][j]=max(f[i-1][j],max(f[i][j],f[i-1][j-c.first]+c.second));
                else f[i][j]=max(f[i-1][j],f[i][j]);
    int ans=0;
    for(int i=0;i<=m;i++)
        ans=max(ans,f[110][i]);

    printf("%d",ans);
}
