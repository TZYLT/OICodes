#include<bits/stdc++.h>
using namespace std;
#define C 2001000
int l[4*C+1],r[4*C+1];
long long add[4*C+1],maxx[4*C+1],v[4*C+1],clear[4*C+1];
int data[C+1];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        maxx[p]=data[li];
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
void spread(int p){
    if(v[p]){
        add[p*2]=0;
        add[p*2+1]=0;
        v[p*2]=1;
        v[p*2+1]=1;
        maxx[p*2]=clear[p];
        maxx[p*2+1]=clear[p];
        clear[p*2]=clear[p];
        clear[p*2+1]=clear[p];
        clear[p]=0;
        v[p]=0;
    }
    if(add[p]){
        add[p*2]+=add[p];
        add[p*2+1]+=add[p];
        maxx[p*2]+=add[p];
        maxx[p*2+1]+=add[p];
        add[p]=0;
    }
}
void change_add(int p,int li,int ri,int d){
    //printf("[%d](%d,%d):max:%d add:%d clear:%d\n",p,l[p],r[p],maxx[p],add[p],clear[p]);
    if(li<=l[p]&&ri>=r[p]){
        add[p]+=d;
        maxx[p]+=d;
        return; 
    }
    spread(p);
    int mid=(l[p]+r[p])/2;
    if(li<=mid)change_add(p*2,li,ri,d);
    if(ri>mid)change_add(p*2+1,li,ri,d);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
void change_t(int p,int li,int ri,int d){
    //printf("[%d](%d,%d):max:%d add:%d clear:%d\n",p,l[p],r[p],maxx[p],add[p],clear[p]);
    
    if(li<=l[p]&&ri>=r[p]){
        add[p]=0;
        maxx[p]=d;
        clear[p]=d;
        v[p]=1;
        return; 
    }
    spread(p);
    int mid=(l[p]+r[p])/2;
    if(li<=mid)change_t(p*2,li,ri,d);
    if(ri>mid)change_t(p*2+1,li,ri,d);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
long long ask(int p,int li,int ri){
    //printf("[%d](%d,%d):max:%d add:%d clear:%d\n",p,l[p],r[p],maxx[p],add[p],clear[p]);
    
    if(li<=l[p]&&ri>=r[p]) return maxx[p];
    spread(p);
    int mid=(l[p]+r[p])/2;
    long long v=-(1ll<<60);
    if(li<=mid)v=max(v,ask(p*2,li,ri));
    if(ri>mid)v=max(v,ask(p*2+1,li,ri));
    return v;
} 

int main(){
    int n,m,op,l,r,x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",data+i);
    build(1,1,n);
    while(m--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&l,&r,&x);
            if(l>r)swap(l,r);
            change_t(1,l,r,x);
        }else if(op==2){
            scanf("%d%d%d",&l,&r,&x);
            if(l>r)swap(l,r);
            change_add(1,l,r,x);
        }else {
            scanf("%d%d",&l,&r);
            if(l>r)swap(l,r);
            printf("%lld\n",ask(1,l,r));
        }
    }
}
