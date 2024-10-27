#include<bits/stdc++.h>
using namespace std;
int a[100100],n;
int stx[100100],stn[100100],hx,hn;
int ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        while(hn&&a[stn[hn]]>=a[i])hn--;
        while(hx&&a[stx[hx]]<a[i])hx--;
        int k=upper_bound(stn+1,stn+hn+1,stx[hx])-stn;
        if(k!=(hn+1))
            ans=max(ans,i-stn[k]+1);
        stn[++hn]=i;
        stx[++hx]=i;
    }
    printf("%d\n",ans);
}