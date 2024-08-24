#include<bits/stdc++.h>
using namespace std;
int n,a0,a1,b0,b1;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        if(b1%a1!=0){
            printf("0\n");
            continue;
        }
        int mul=b1/a1,t=a0/a1,ans=0;
        for(int i=1;i*i<=mul;i++)
            if(mul%i==0&&b1%i==0){
                int q=mul/i,k=i;
                if(__gcd(q,t)==1&&(1ll*a1*q*b0)/__gcd(a1*q,b0)==b1)ans++;
                swap(q,k);
                if(q!=k)if(__gcd(q,t)==1&&(1ll*a1*q*b0)/__gcd(a1*q,b0)==b1)ans++;
            }
        printf("%d\n",ans);
    }
}