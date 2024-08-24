#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int t,n,m,a[100100],b[100100];
void ad(int &x,int y){x=(x+y)%p;}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d",a+i);
        for(int i=1;i<=m;i++)
            scanf("%d",b+i);
        int f[m+10][n+10];
        memset(f,0,sizeof f);
        f[0][0]=1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++)
                for(int k=0;k<=j;k++)
                    if(a[i+1]==0&&b[i+1]==0){
                        ad(f[i+1][j-k],f[i][j-k]);
                        ad(f[i+1][j-k+1],f[i][j-k]);
                        ad(f[i+1][j-k-1],f[i][j-k]);
                        ad(f[i+1][j-k],f[i][j-k]);
                    }else if(a[i+1]==1&&b[i+1]==0){
                        ad(f[i+1][j-k],f[i][j-k]);
                        ad(f[i+1][j-k+1],f[i][j-k]);
                    }else if(a[i+1]==0&&b[i+1]==1){
                        ad(f[i+1][j-k],f[i][j-k]);
                        ad(f[i+1][j-k-1],f[i][j-k]);
                    }else if(a[i+1]==1&&b[i+1]==1){
                        ad(f[i+1][j-k],f[i][j-k]);
                    }
        }
        printf("%d\n",(f[m][n]%p+p)%p);
    }
}