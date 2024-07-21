#include<bits/stdc++.h>
using namespace std;
#define M 200200
int n,q,a[M],b[M],c[M],ans;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        b[a[i]]++;
    for(int i=1;i<=n;i++)
        if(b[i]){
            c[i+1]--;
            c[max(1,i-b[i]+1)]++;
        }
    for(int i=1;i<=n;i++){
        c[i]+=c[i-1];
        ans+=(c[i]==0);
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(b[a[x]]<=a[x]){
            c[a[x]-b[a[x]]+1]--;
            if(c[a[x]-b[a[x]]+1]==0)ans++;
        }
        b[a[x]]--;
        b[y]++;
        if(b[y]<=y){
            c[y-b[y]+1]++;
            if(c[y-b[y]+1]==1)ans--;
        }
        a[x]=y;
        printf("%d\n",ans);
    }


}