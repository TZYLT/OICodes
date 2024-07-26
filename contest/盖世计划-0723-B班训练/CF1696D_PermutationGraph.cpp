#include<bits/stdc++.h>
using namespace std;
#define M 500500
int a[M],n,id[M];

int l[4*M+1],r[4*M+1];
int minn[4*M+1],maxx[4*M+1];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        maxx[p]=a[li];
        minn[p]=a[li];
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    minn[p]=min(minn[p*2],minn[p*2+1]);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
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
    int v=(1<<30);
    if(li<=mid)v=min(v,askmin(p*2,li,ri));
    if(ri>mid)v=min(v,askmin(p*2+1,li,ri));
    return v;
} 
int ans=0;
void search(int l,int r){
    if(l>=r)return;
    ans++;
    if(l+1==r)return;
    int minn=askmin(1,l,r);
    int maxx=askmax(1,l,r);
    search(l,min(id[minn],id[maxx]));
    search(max(id[minn],id[maxx]),r);
}
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            id[a[i]]=i;
        build(1,1,n);
        search(1,n);
        printf("%d\n",ans);
    }
}