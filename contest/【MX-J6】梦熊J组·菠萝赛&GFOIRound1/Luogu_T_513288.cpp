#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int n,k,a[101];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),m[a[i]]=1;
    for(int i=1;i<=n;i++)
        if(m.count(a[i]-k)||m.count(a[i]+k)){
            printf("Yes\n");
            return 0;
        }
    printf("No\n");
}