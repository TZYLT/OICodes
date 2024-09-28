#include<bits/stdc++.h>
using namespace std;
set<int> s;
int a[1001000],n,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int ans=0;
        int l=1,r=0;
        while(r<n){
            r++;
            while(s.count(a[r]))s.erase(a[l++]);
            s.insert(a[r]);
            ans=max(ans,r-l+1);
            //printf("[%d,%d]",l,r);
        }
        printf("%d\n",ans);
        s.clear();
    }
}