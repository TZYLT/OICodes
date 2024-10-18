#include<bits/stdc++.h>
using namespace std;
int a[13];
string s;
int c,t,n;
int dp[100100],sum[100100];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>s;n=s.size();
        for(int i=1;i<=9;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++){
            dp[i]=a[s[i-1]-'0'];sum[i]=s[i-1]-'0';
            int id=0,minn=0x3f3f3f3f;
            for(int j=1;j<i;j++){
                if(minn>sum[j]*10-dp[j]&&sum[j]*10-dp[j]<0)
                    minn=sum[j]*10-dp[j],id=j;
            }
            if(id!=0)dp[i]+=dp[id],sum[i]+=sum[id]*10;
            printf("%d %d\n",dp[i],sum[i]);
        }
        int ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++)
            ans=min(ans,sum[i]-dp[i]);
        //printf("%d\n",ans);
        for(int i=1;i<=n;i++)
            ans+=a[s[i-1]-'0'];
        printf("%d\n",ans);
    }
    
    
}