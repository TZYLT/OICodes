#include<bits/stdc++.h>
using namespace std;
int n,m,mmax,l=(1<<30),a[200100];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        mmax=max(x,mmax);
    }

    for(int i=mmax;i<=n;i++)
        l=min(l,a[i]);
    
    printf("%d\n",l);
    
}