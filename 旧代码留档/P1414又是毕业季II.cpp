#include<bits/stdc++.h>
using namespace std;
#define M 1001000
int bt[M];
int ans[M];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        bt[x]++;
    }
    for(int i=1;i<=1000000;i++){
        int sum=0;
        for(int j=i;j<=1000000;j+=i)
            sum+=bt[j];
        ans[sum]=i;
    }
    for(int i=n;i>=1;i--){
        ans[i]=max(ans[i],ans[i+1]);
        
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
}