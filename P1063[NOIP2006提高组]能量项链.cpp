#include<bits/stdc++.h>
using namespace std;
int f[210][210],n;
int a[210];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),a[i+n]=a[i];
    a[2*n+1]=a[1];    
    for(int l=2;l<=n;l++)
        for(int x=1;x+l-1<=2*n;x++)
            for(int m=x;m<(x+l-1);m++)
                f[x][x+l-1]=max(f[x][x+l-1],f[x][m]+f[m+1][x+l-1]+a[x]*a[m+1]*a[x+l]);

    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i][i+n-1]);
    printf("%d\n",ans);
}