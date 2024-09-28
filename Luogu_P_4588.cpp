#include<bits/stdc++.h>
using namespace std;
#define C 100100
int l[4*C+1],r[4*C+1];
long long sum[4*C+1];
int m;
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        sum[p]=1;
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    sum[p]=1ll*sum[p*2]*sum[p*2+1]%m;
}
void change(int p,int d,int x){
    if(l[p]==d&&r[p]==d)return sum[p]=x,void();
    int mid=(l[p]+r[p])/2;
    if(d<=mid) change(p<<1,d,x);
    else change((p<<1)|1,d,x);
    sum[p]=1ll*sum[p*2]*sum[p*2+1]%m;
}
int ask(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return sum[p];
    int mid=(l[p]+r[p])/2;
    int v=1;
    if(li<=mid)v=1ll*v*ask(p*2,li,ri)%m;
    if(ri>mid)v=1ll*v*ask(p*2+1,li,ri)%m;
    return v;
} 
int t,q;
int main(){
    scanf("%d",&t);
    while(t--){
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        memset(sum,0,sizeof sum);

        scanf("%d%d",&q,&m);
        build(1,1,q);
        for(int i=1;i<=q;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==1){
                change(1,i,y);
                printf("%d\n",ask(1,1,q));
            }else{
                change(1,y,1);
                printf("%d\n",ask(1,1,q));
            }
        }
    }
    

}
