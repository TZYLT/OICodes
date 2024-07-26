#include<bits/stdc++.h>
using namespace std;
#define C 100100
int l[4*C+1],r[4*C+1];
long long maxx[4*C+1],minn[4*C+1];
long long dt[C+1],c[C];
int n,q,a[C],b[C];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        maxx[p]=minn[p]=dt[li];
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
    minn[p]=min(minn[p*2],minn[p*2+1]);
}
long long askmax(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return maxx[p];
    int mid=(l[p]+r[p])/2;
    long long v=-(1ll<<60);
    if(li<=mid)v=max(v,askmax(p*2,li,ri));
    if(ri>mid)v=max(v,askmax(p*2+1,li,ri));
    return v;
} 
long long askmin(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return minn[p];
    int mid=(l[p]+r[p])/2;
    long long v=1ll<<60;
    if(li<=mid)v=min(v,askmin(p*2,li,ri));
    if(ri>mid)v=min(v,askmin(p*2+1,li,ri));
    return v;
} 
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    for(int i=1;i<=n;i++)
        c[i]=a[i]-b[i];
    for(int i=1;i<=n;i++)
        dt[i]=dt[i-1]+c[i];
    
    build(1,1,n);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        if((dt[r]-dt[l-1])!=0){
            printf("-1\n");
            continue;
        }
        if((askmax(1,l,r)-dt[l-1])>0){
            printf("-1\n");
            continue;
        }
        printf("%lld\n",dt[l-1]-askmin(1,l,r));
    }
}