#include<bits/stdc++.h>
using namespace std;
int n,k,p,a[1001000],c[1001000];
long long ans;
int num[100100],l,t;
int main(){
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++)
        scanf("%d%d",a+i,c+i);
    for(int i=1;i<=n;i++){
        if(c[i]<=p){
            l=t,t=i;
            for(int j=l+1;j<=t;j++)
                num[a[j]]++;
            ans+=num[a[i]]-1;
        }
        else ans+=num[a[i]];
    }
    printf("%lld\n",ans);
}