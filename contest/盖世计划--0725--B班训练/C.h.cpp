#include<bits/stdc++.h>
using namespace std;
int f[505][505];
int g[505][505][256];
int a[505],b[505];
int t,n;
inline int x(int l,int r){
    return b[l-1]^b[r];
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   
            scanf("%d",a+i);
        for(int i=1;i<=n;i++)
            b[i]=b[i-1]^a[i];
        for(int i=1;i<=n;i++)
            f[i][i]=1;
        for(int i=1;i<=n;i++)
            for(int l=1;l<=i;l++)
                for(int r=i;r<=n;r++)
                    g[l][r][a[i]]=1;
        for(int len=3;len<=n;len++)
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                for(int i=l;i<r&&f[l][r]==0;i++)
                    if(f[l][i])
                    for(int j=r;j>=i+1&&f[l][r]==0;j--)
                        if(f[j][r])
                            if(g[i+1][j-1][x(l,i)^x(j,r)])
                                f[l][r]=1;
                for(int i=1;i<=l;i++)
                    for(int j=r;j<=n;j++)
                        g[i][j][x(l,r)]=1;
            }
        printf(f[1][n]?"YES\n":"NO\n");
    }
}