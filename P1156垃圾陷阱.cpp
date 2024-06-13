#include<bits/stdc++.h>
using namespace std;
struct dt{
    int t,h,l;
}c[110];
int n,m,lv[110],f[110];
bool cmp(dt a,dt b){
    return a.t<b.t;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&c[i].t,&c[i].l,&c[i].h);
    sort(c+1,c+1+m,cmp);
    f[0]=10;
    for(int i=1;i<=m;i++)
      for(int j=n;j>=0;j--)
        if(f[j]>=c[i].t){
            if(j+c[i].h>=n){
                printf("%d",c[i].t);
                return 0;
            }
            f[j+c[i].h]=max(f[j+c[i].h],f[j]);
            f[j]+=c[i].l;
        }
    printf("%d",f[0]);
    return 0;
}
