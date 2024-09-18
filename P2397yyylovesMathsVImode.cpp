#include<bits/stdc++.h>
using namespace std;
int cnt,val,n,x;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(cnt==0)val=x,cnt++;
        else if(val==x)cnt++;
        else cnt--;
    }
    printf("%d\n",val);
}