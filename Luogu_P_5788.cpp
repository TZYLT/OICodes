#include<bits/stdc++.h>
using namespace std;
int a[3001000];
int st[3003000],h,n;
int ans[3003000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        while(a[st[h]]<=a[i]&&h>=1)h--;
        ans[i]=st[h];
        st[++h]=i;
    }
    for(int i=1;i<=n;i++)
        if(ans[i])ans[i]=n-ans[i]+1;
    reverse(ans+1,ans+1+n);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
}