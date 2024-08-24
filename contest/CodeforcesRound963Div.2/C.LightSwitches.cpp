#include<bits/stdc++.h>
using namespace std;
int t,n,k;
long long aa[200200];
#define C 400200


int l[4*C+1],r[4*C+1];
long long sum[4*C+1],add[4*C+1];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;add[p]=0;
    if(li==ri){
        sum[p]=1;
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    sum[p]=sum[p*2]+sum[p*2+1];
}
void spread(int p){
    if(add[p]){
        sum[p*2]=0;
        sum[p*2+1]=0;
        add[p*2]|=add[p];
        add[p*2+1]|=add[p];
        add[p]=0;
    }
}
void change(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]){
        sum[p]=0;
        add[p]=1;
        return; 
    }
    spread(p);
    int mid=(l[p]+r[p])/2;
    if(li<=mid)change(p*2,li,ri);
    if(ri>mid)change(p*2+1,li,ri);
    sum[p]=sum[p*2]+sum[p*2+1];
}
int ask(int p){
    spread(p);
    if(l[p]==r[p])return l[p];
    if(sum[p*2]>0)return ask(p*2);
    else return ask(p*2+1);
}
int main(){
    scanf("%d",&t);
    while(t--){

        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%lld",&aa[i]);
        sort(aa+1,aa+1+n);
        build(1,0,2*k-1);
        int f=0;
        for(int i=1;i<=n;i++){
            long long x=aa[i]%(k*2);
            if(x==0)change(1,k,k*2-1);
            else if(x==k)change(1,0,k-1);
            else if(x>0&&x<k){
                change(1,0,x-1);
                change(1,x+k,k*2-1);
            }else change(1,x-k,x-1),f=1;
            //printf("%lld,%lld\n",ask(1),sum[1]);
        }
        if(sum[1]>0){
            long long ans=0;
            ans=ask(1);
            if(f==0)printf("%lld\n",aa[n]-aa[n]%(2*k)+ans);
            else printf("%lld\n",aa[n]-aa[n]%(2*k)+2*k+ans);
        }
        else printf("-1\n");
       // if(b.first<=b.second)ans=min(ans,b.first);
        
    }
}