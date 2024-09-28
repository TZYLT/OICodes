#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[101];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int l=-1,r=-1;
        for(int i=1;i<=n;i++)
            if(i&1)l=max(l,a[i]);
            else r=max(r,a[i]);
        printf("%d\n",max(l+((n+1)/2),r+(n/2)));
    }
}