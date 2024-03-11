#include<bits/stdc++.h>
using namespace std;
int dp[100][10][2][2],ans,a,b;
int f(int x){
    int a[20]={0},b[20]={0},le=0;
    dp[0][0][1][1]=1;
    while(x) a[le++]=x%10,x/=10;//25->5 2
    for(int i=0;i<le;i++)
        b[i+1]=a[le-i-1];
    for(auto c:b)printf("%d ",c);
    putchar('\n');
    for(int i=0;i<le;i++)
        for(int j=0;j<=9;j++)  
            for(int l=0;l<=1;l++)
                for(int z=0;z<=1;z++)
                    for(int k=0;k<=9;k++){
                        printf("[%d,%d,%d,%d]->[%d,%d,%d,%d]:%d\n",i,j,l,z,i+1,k,l&&k==b[i+1],z&&!k,dp[i][j][l][z]);
                        if(!z&&abs(j-k)<2)continue;
                        if(l&&k>b[i+1])break;
                        dp[i+1][k][l&&k==b[i+1]][z&&!k]+=dp[i][j][l][z];
                    }
    int t=-1;
    for(int i=0;i<le;i++)
        for(int j=0;j<=9;j++)  
            for(int l=0;l<=1;l++)
                for(int z=0;z<=1;z++)
                    t=max(t,dp[i][j][l][z]);
    return t;
}
int main(){
    scanf("%d%d",&a,&b);
    memset(dp,0,sizeof(dp));
    ans=f(b);
    memset(dp,0,sizeof(dp));
    printf("%d\n",ans);
}