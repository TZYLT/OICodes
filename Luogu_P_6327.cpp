#include<bits/stdc++.h>
using namespace std;
#define C 200200
int l[4*C+1],r[4*C+1];
double s[4*C+1],c[4*C+1],add[4*C+1];
double data[C+1];
void pushup(int p){
    s[p]=s[p*2]+s[p*2+1];
    c[p]=c[p*2]+c[p*2+1];
}
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        s[p]=sin(data[li]);
        c[p]=cos(data[li]);
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    pushup(p);
}
void upd(int p,double d){
    double cc=c[p],ss=s[p];
    s[p]=ss*cos(d)+cc*sin(d);
    c[p]=cc*cos(d)-ss*sin(d);
}
void spread(int p){
    upd(p*2,add[p]);
    upd(p*2+1,add[p]);
    add[p*2]+=add[p];
    add[p*2+1]+=add[p];
    add[p]=0;
}
void change(int p,int li,int ri,double d){
    if(li<=l[p]&&ri>=r[p]){
        upd(p,d);
        add[p]+=d;
        return; 
    }
    spread(p);
    int mid=(l[p]+r[p])/2;
    if(li<=mid)change(p*2,li,ri,d);
    if(ri>mid)change(p*2+1,li,ri,d);
    pushup(p);
}
double ask(int p,int li,int ri){ 
    if(li<=l[p]&&ri>=r[p]) return s[p];
    spread(p);
    int mid=(l[p]+r[p])/2;
    double v=0;
    if(li<=mid)v+=ask(p*2,li,ri);
    if(ri>mid)v+=ask(p*2+1,li,ri);
    return v;
}
int n,m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf",&data[i]);
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
        int op,l,r,x;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            scanf("%d",&x);
            change(1,l,r,x);
        }else{
            printf("%.1lf\n",ask(1,l,r));
        }
    }
}