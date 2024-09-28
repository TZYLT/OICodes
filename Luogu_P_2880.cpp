#include<bits/stdc++.h>
using namespace std;
#define C 200200
int l[4*C+1],r[4*C+1];
long long maxx[4*C+1],minn[4*C+1];
int data[C+1];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        maxx[p]=data[li];
        minn[p]=data[li];
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
    minn[p]=min(minn[p*2],minn[p*2+1]);
}
int askmax(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return maxx[p];
    int mid=(l[p]+r[p])/2;
    int v=0;
    if(li<=mid)v=max(v,askmax(p*2,li,ri));
    if(ri>mid)v=max(v,askmax(p*2+1,li,ri));
    return v;
} 
int askmin(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return minn[p];
    int mid=(l[p]+r[p])/2;
    int v=0x7f7f7f7f;
    if(li<=mid)v=min(v,askmin(p*2,li,ri));
    if(ri>mid)v=min(v,askmin(p*2+1,li,ri));
    return v;
} 

int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",data+i);
    build(1,1,n);
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",askmax(1,l,r)-askmin(1,l,r));
    }
}