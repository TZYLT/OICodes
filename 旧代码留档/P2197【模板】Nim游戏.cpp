#include<bits/stdc++.h>
using namespace std;
int t,n,s;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);s=0;
        for(int i=1,x;i<=n;i++)
            scanf("%d",&x),s^=x;
        if(s)printf("Yes\n");
        else printf("No\n");
    }
}