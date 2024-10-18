#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    unsigned sum[20],add;
}tr[1000100];
unsigned C[200200][25],a[200200];
unsigned pw[1<<20][22];
void pushup(int p){
    for(int i=0;i<=19;i++)
        tr[p].sum[i]=0;
    for(int i=0;i<=19;i++)
        for(int j=0;j<=i;j++)
            tr[p].sum[i]+=tr[p<<1].sum[j]*tr[p<<1|1].sum[i-j];
}
void updata(int p,unsigned d){
    unsigned sut[20]={0};d&=1048575;
    for(int i=0;i<=19;i++)
        for(int j=0;j<=min(i,(tr[p].r-tr[p].l+1));j++)
            sut[i]+=tr[p].sum[j]*C[(tr[p].r-tr[p].l+1)-j][i-j]*pw[d][i-j];
    for(int i=0;i<=19;i++)
        tr[p].sum[i]=sut[i];
}
void pushdown(int p){
    if(tr[p].add){
        updata(p<<1,tr[p].add);
        updata(p<<1|1,tr[p].add);
        tr[p<<1].add+=tr[p].add;
        tr[p<<1|1].add+=tr[p].add;
        tr[p].add=0;
    }
}
void build(int p,int l,int r){
    tr[p].l=l;tr[p].r=r;
    if(l==r){
        tr[p].sum[1]=a[l];
        tr[p].sum[0]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void change(int p,int l,int r,unsigned d){
    if(l<=tr[p].l&&tr[p].r<=r){
        updata(p,d);
        tr[p].add+=d;
        return ;
    }
    pushdown(p);
    int mid=(tr[p].l+tr[p].r)>>1;
    if(l<=mid)change(p<<1,l,r,d);
    if(r>mid)change(p<<1|1,l,r,d);
    pushup(p);
}
unsigned ask(int p,int l,int r){
    if(l<=tr[p].l&&tr[p].r<=r){
        unsigned su=0;
        for(int i=0;i<=19;i++)
            su+=tr[p].sum[i];
        return su;
    }
    pushdown(p);
    int mid=(tr[p].l+tr[p].r)>>1;
    unsigned su=1;
    if(l<=mid)su*=ask(p<<1,l,r);
    if(r>mid)su*=ask(p<<1|1,l,r);
    return su;
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    C[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=min(i,20);j++)
            if(j==0)C[i][j]=C[i-1][j];
            else C[i][j]=(C[i-1][j-1]+C[i-1][j]);
    for(unsigned i=0;i<(1<<20);i++){
        pw[i][0]=1;
        for(int j=1;j<=20;j++)  
            pw[i][j]=pw[i][j-1]*i;
            
    }
    for(int i=1;i<=n;i++)
        scanf("%u",a+i),a[i]--;
    build(1,1,n);
    while(m--){
        int op,l,r,x;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            scanf("%u",&x);
            change(1,l,r,x);
        }else{
            printf("%u\n",ask(1,l,r)&1048575);
        }
    }
}