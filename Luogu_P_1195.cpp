#include<bits/stdc++.h>
using namespace std;
int fa[10010];
int get(int x){
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    if(get(x)==get(y))return;
    fa[get(x)]=get(y);
}
int n,m,k;
struct eg{
    int x,y,z;
    friend bool operator<(eg x,eg y){
        return x.z<y.z;
    }
}e[100100];
long long ans;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(e+1,e+1+m);
    for(int i=1;i<=m;i++){
        if(k==n)break;
        if(get(e[i].x)==get(e[i].y))continue;
        ans+=e[i].z;k++;merge(e[i].x,e[i].y);
    }   
    if(k<n)printf("No Answer\n");
    else printf("%lld",ans);
}