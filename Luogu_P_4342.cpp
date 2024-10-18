#include<bits/stdc++.h>
using namespace std;
char c[1010];
int a[1010],f[1010][1010],g[1010][1010];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i]>>a[i];
    for(int i=1;i<=n;i++)
        c[i+n]=c[i],a[i+n]=a[i];
    memset(f,0xcf,sizeof f);
    memset(g,0x3f,sizeof g);
    int ans=0xcf3f3f3f;
    for(int i=1;i<=n*2;i++)
        f[i][i]=g[i][i]=a[i];
    for(int len=2;len<=n;len++)
        for(int l=1,r=len;r<=2*n;l++,r++)
            for(int k=l;k<r;k++){
                if(c[k+1]=='t'){
                    f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]);
                    g[l][r]=min(g[l][r],g[l][k]+g[k+1][r]);
                }else{
                    f[l][r]=max({f[l][r],f[l][k]*f[k+1][r],f[l][k]*g[k+1][r],g[l][k]*f[k+1][r],g[l][k]*g[k+1][r]});
                    g[l][r]=min({g[l][r],f[l][k]*f[k+1][r],f[l][k]*g[k+1][r],g[l][k]*f[k+1][r],g[l][k]*g[k+1][r]});
                }
            }  
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i][i+n-1]);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        if(f[i][i+n-1]==ans)
            printf("%d ",i);
      
}