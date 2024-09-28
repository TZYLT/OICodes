#include<bits/stdc++.h>
using namespace std;
//#define _int128 long long
__int128 dp[101][101],ans;
int a[101];
int n,m;
void print(__int128 x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
int main(){
    scanf("%d%d",&n,&m);
    while(n--){
        memset(a,0,sizeof a);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=m;i++)
            scanf("%d",a+i);
        for(int i=1;i<=m;i++)
            dp[i][i]=a[i]*2;
        for(int len=2;len<=m;len++)
            for(int l=1,r=l+len-1;r<=m;l++,r++)
                dp[l][r]=max(dp[l][r-1]*2+a[r]*2,dp[l+1][r]*2+a[l]*2);
        ans+=dp[1][m];
    }
    print(ans);
}