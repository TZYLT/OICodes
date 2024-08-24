#include<bits/stdc++.h>
using namespace std;
struct node{
    int lc,rc,fa;
    int minn,maxx,w;
    int tag;
}tr[300200];
int ans=0;
void build(int x){
    int f=1;
    tr[x].maxx=tr[x].minn=tr[x].w;
    if(tr[x].lc!=0){
        build(tr[x].lc);
        tr[x].maxx=max(tr[x].maxx,tr[tr[x].lc].maxx);
        tr[x].minn=min(tr[x].minn,tr[tr[x].lc].minn);
        if(tr[tr[x].lc].tag==0||tr[tr[x].lc].maxx>tr[x].w)f=0;
    }
    if(tr[x].rc!=0){
        build(tr[x].rc);
        tr[x].maxx=max(tr[x].maxx,tr[tr[x].rc].maxx);
        tr[x].minn=min(tr[x].minn,tr[tr[x].rc].minn);
        if(tr[tr[x].rc].tag==0||tr[tr[x].rc].minn<tr[x].w)f=0;
    }
    tr[x].tag=f;
    if(tr[x].tag==1)ans++;
    //printf("[%d]:%d\n",x,tr[x].tag);
}
void change(int x,int q,int d){
    if(x==0)return;
    if(q==x){tr[x].w=d;}
    int l=tr[x].tag,a=tr[x].maxx,b=tr[x].minn,f=1;
    tr[x].maxx=tr[x].minn=tr[x].w;
    if(tr[x].lc!=0){
        tr[x].maxx=max(tr[x].maxx,tr[tr[x].lc].maxx);
        tr[x].minn=min(tr[x].minn,tr[tr[x].lc].minn);
        if(tr[tr[x].lc].tag==0||tr[tr[x].lc].maxx>tr[x].w)f=0;
    }
    if(tr[x].rc!=0){
        tr[x].maxx=max(tr[x].maxx,tr[tr[x].rc].maxx);
        tr[x].minn=min(tr[x].minn,tr[tr[x].rc].minn);
        if(tr[tr[x].rc].tag==0||tr[tr[x].rc].minn<tr[x].w)f=0;
    }
    tr[x].tag=f;
    if(tr[x].tag==0&&l==1)ans--;
    if(tr[x].tag==1&&l==0)ans++;
    if(tr[x].tag==l&&tr[x].maxx==a&&tr[x].minn==b)return;
    change(tr[x].fa,q,d);
    //printf("[%d]:%d\n",x,tr[x].tag);
}
int n,q;
int main(){
    freopen("bst.in","r",stdin);
    freopen("bst.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&tr[i].lc,&tr[i].rc);
        tr[tr[i].lc].fa=i;
        tr[tr[i].rc].fa=i;
    }for(int i=1;i<=n;i++){
        scanf("%d",&tr[i].w);
    }
    build(1);
    while(q--){
        int k,x;
        scanf("%d%d",&k,&x);
        change(k,k,x);
        printf("%d\n",ans);
    }
}