#include<bits/stdc++.h>
using namespace std;
struct node{
    int lc,rc,dt;
}tr[20001000];
int root[20001000],cnt;
struct dot{
    int id,x,y,z;
};
int n,k;
int ans[5000100];
dot data[5000100];

bool cmp(dot a,dot b){
    if(a.x==b.x&&a.y==b.y) return a.z<b.z;
    else if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}
int change(int rt,int l,int r,int x){
    //printf("[%d->%d](%d,%d):%d\n",rt,cnt+1,l,r,x);
    int p=++cnt;
    tr[p]=tr[rt];
    tr[p].dt++;
    int mid=(l+r)>>1;
    if(l<r){
        if(x<=mid)tr[p].lc=change(tr[rt].lc,l,mid,x);
        else tr[p].rc=change(tr[rt].rc,mid+1,r,x);
    }
    return p;
}
int ask(int rt,int l,int r,int u){
    if(1<=l&&r<=u)return tr[rt].dt;
    int mid=(l+r)>>1;
    int ans=0;
    if(1<=mid)ans+=ask(tr[rt].lc,l,mid,u);
    if(u>mid)ans+=ask(tr[rt].rc,mid+1,r,u);
    return ans;
}
int ask(int x,int y){
    int ans=0;
    for(;x;x-=x&-x)ans+=ask(root[x],1,k,y);
    return ans;
}
void add(int x,int y){
    for(;x<=k;x+=x&-x){
        //printf("[%d:%d](%d,%d)\n",x,root[x],x,y);
        root[x]=change(root[x],1,k,y);
    }  
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&data[i].x,&data[i].y,&data[i].z);
        data[i].id=i;
    }
    sort(data+1,data+1+n,cmp);
    for(int i=1;i<=n;i++){
        ans[ask(data[i].y,data[i].z)]++;
        add(data[i].y,data[i].z);
    }
    
    for(int i=0;i<=n;i++)
        printf("%d\n",ans[i]);
    
}