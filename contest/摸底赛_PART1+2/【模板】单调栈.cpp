#include<bits/stdc++.h>
using namespace std;
int st[3003000],h;
int a[3003000],ans[3003000],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        while(h&&a[st[h]]<=a[i])h--;
        ans[i]=st[h];
        st[++h]=i;
    }
    reverse(ans+1,ans+1+n);
    for(int i=1;i<=n;i++)
        if(ans[i])ans[i]=n-ans[i]+1;
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
}