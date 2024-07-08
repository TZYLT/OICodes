#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[1010][1010];
int x[1010],y[1010];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);

    for(int i=1;i<=n;i++) x[i]=i;
    for(int i=1;i<=m;i++) y[i]=i;

    while(q--){
        int op,xx,yy;
        scanf("%d%d%d",&op,&xx,&yy);

        if(op==1)swap(x[xx],x[yy]);
        else if(op==2)swap(y[xx],y[yy]);
        else {
            printf("%d\n",a[x[xx]][y[yy]]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",a[x[i]][y[j]]);
        printf("\n");
    }
        
}