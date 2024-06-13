#include<bits/stdc++.h>
using namespace std;
int f[250][250];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i][i]);

    for(int l=2;l<=n;l++)
        for(int x=1;x+l-1<=n;x++)
            for(int m=x;m<=(x+l-1);m++)
                if(f[x][m]==f[m+1][x+l-1]&&f[x][m]!=0)
                    f[x][x+l-1]=max(f[x][x+l-1],f[x][m]+1);
    int ans=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans=max(ans,f[i][j]);
    
    printf("%d\n",ans);
}