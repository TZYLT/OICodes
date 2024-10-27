#include<bits/stdc++.h>
using namespace std;
int dp[5050][55];
int n,m,k;
int main(){
    scanf("%d%d%d",&k,&m,&n);
    memset(dp,0xcf,sizeof dp);
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
        int c,w;
        scanf("%d%d",&c,&w);
        for(int j=m;j>=c;j--){
            int tmp[55]={0};
            int l=1,r=1;
            while(l+r-2<=k){
                if(dp[j-c][l]+w<dp[j][r])
                    tmp[l+r-1]=dp[j][r],r++;
                else tmp[l+r-1]=dp[j-c][l]+w,l++;
            }
            for(int t=1;t<=k;t++)
                dp[j][t]=tmp[t];
            //printf("\n");
        }
    }
    int ans=0;
    for(int i=1;i<=k;i++)
        ans+=dp[m][i];
    printf("%d\n",ans);
}