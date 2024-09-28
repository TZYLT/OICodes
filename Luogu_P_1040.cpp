#include<bits/stdc++.h>
using namespace std;
long long f[32][32][32];
int lc[32][32][32][2];
long long n,w[32];
void dfs(int x,int l,int r){
    printf("%d ",x);
    if(lc[x][l][r][0]){
        dfs(lc[x][l][r][0],l,x-1);
    }
    if(lc[x][l][r][1]){
        dfs(lc[x][l][r][1],x+1,r);
    }
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",w+i);
    for(int i=1;i<=n;i++)   
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                f[i][j][k]=1;
    for(int i=1;i<=n;i++)
        f[i][i][i]=w[i];
    for(int len=2;len<=n;len++)
        for(int l=1,r=l+len-1;r<=n;l++,r++)
            for(int i=l;i<=r;i++){
                for(int x=l;x<i;x++)
                    for(int y=i+1;y<=r;y++)
                        if(f[i][l][r]<(f[x][l][i-1]*f[y][i+1][r]+w[i])){
                            f[i][l][r]=(f[x][l][i-1]*f[y][i+1][r]+w[i]);
                            lc[i][l][r][0]=x;lc[i][l][r][1]=y;
                        }
                if(i==l)
                    for(int y=i+1;y<=r;y++)
                        if(f[i][l][r]<f[y][l+1][r]+w[l]){
                            f[i][l][r]=f[y][l+1][r]+w[l];
                            lc[i][l][r][0]=0;lc[i][l][r][1]=y;
                        }
                if(i==r)
                    for(int x=l;x<i;x++) 
                        if(f[i][l][r]<f[x][l][r-1]+w[r]){
                            f[i][l][r]=f[x][l][r-1]+w[r];
                            lc[i][l][r][0]=x;lc[i][l][r][1]=0;
                        }
            }        

    
    long long ans=0,t=0;
    for(int i=1;i<=n;i++)        
        if(ans<f[i][1][n])ans=f[i][1][n],t=i;
    printf("%lld\n",ans);
    dfs(t,1,n);
}