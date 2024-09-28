#include<bits/stdc++.h>
using namespace std;
int st[300300],h=0;
int n,ans;
int x,y;
int main(){
    scanf("%d",&n);ans=n;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        int l=0;
        while(st[h]>=y&&h>=1)l=st[h--];
        if(l==y)ans--;
        st[++h]=y;
    }
    printf("%d\n",ans);
}