#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int n,t,dp[1010];
char cc;
int main(){
    cin>>a>>cc>>b>>c>>cc>>d>>n;
    t=60*(c-a)+(d-b);
    for(int k=1;k<=n;k++){
        int W,C,p;
        scanf("%d%d%d",&C,&W,&p);
        if(p==0){
            for(int i=C;i<=t;i++)
                dp[i]=max(dp[i],dp[i-C]+W);
        }else{
            for(int i=t;i>=C;i--)
                for(int j=1;j<=p&&j*C<=i;j++)
                    dp[i]=max(dp[i],dp[i-C*j]+W*j);
            // for (int j = 1; j <= p && j * ; j++)
            //     dp[i] = max(dp[i], dp[i - j * C] + W * j);    
        }
    }
    int ans=0;
    for(int i=0;i<=t;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);

}