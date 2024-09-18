#include<bits/stdc++.h>
using namespace std;
bool v[300100];
int p[30010],k,ans=1;
void linearSieve_mu(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
bool isp(int x){
    if(x==1)return 0;
    for(int i=2;p[i]*p[i]<=x;i++)
        if(x%p[i]==0)return 0;
    return 1;
}
int n;
int main(){
    scanf("%d",&n);
    linearSieve_mu(300000);
    if(n<=300000){
        for(int i=1;i<=k;i++)
            if(n>=p[i])
                ans=((long long)ans*p[i])%1000000007;
        printf("%d ",ans);
    }
    else{
        for(int i=1;i<=k;i++)
                ans=((long long)ans*p[i])%1000000007;
        for(int i=300001;i<=n;i+=2)
            if(isp(i))
             ans=((long long)ans*i)%1000000007;
        printf("%d\n",ans);
    }
}