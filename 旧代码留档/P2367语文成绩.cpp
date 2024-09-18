#include<bits/stdc++.h>
using namespace std;
int n,p,a[5000500],b[5005000];

int main(){
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        b[i]=a[i]-a[i-1];
    while(p--){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        b[l]+=x;
        b[r+1]-=x;
    }
    int sum=0,minn=(1<<30);
    for(int i=1;i<=n;i++){
        sum+=b[i];
        minn=min(minn,sum);
    }
    printf("%d\n",minn);
}