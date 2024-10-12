#include<bits/stdc++.h>
using namespace std;
struct nd{
    int x,y;
    friend nd operator+(nd x,nd y){
        nd t;
        if(x.x>y.x) t.x=x.x,t.y=max(x.y,y.x);
        else t.x=y.x,t.y=max(x.x,y.y);
        return t;
    }
}a[1<<19];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++)
        scanf("%d",&a[i].x),a[i].y=-(1<<29);
    for(int j=0;j<n;j++)
        for(int i=0;i<(1<<n);i++)
            if(i&(1<<j))
                a[i]=a[i]+a[i^(1<<j)];
    int ans=0;
    for(int i=1;i<(1<<n);i++){
        ans=max(ans,a[i].x+a[i].y);
    printf("%d\n",ans);}
}