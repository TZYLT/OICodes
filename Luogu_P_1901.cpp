#include<bits/stdc++.h>
using namespace std;
#define M 1001000
int v[M],h[M],st[M],head;
int n;
int ans[M];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",h+i,v+i);
    for(int i=1;i<=n;i++){
        while(head&&h[st[head]]<=h[i])head--;
        ans[st[head]]+=v[i];
        st[++head]=i;
    }
    reverse(v+1,v+1+n);
    reverse(h+1,h+1+n);
    reverse(ans+1,ans+1+n);
    head=0;
    for(int i=1;i<=n;i++){
        while(head&&h[st[head]]<=h[i])head--;
        ans[st[head]]+=v[i];
        st[++head]=i;
    }
    int anns=0;
    for(int i=1;i<=n;i++)
        anns=max(anns,ans[i]);
    printf("%d",anns);
}