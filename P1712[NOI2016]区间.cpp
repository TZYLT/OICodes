#include<bits/stdc++.h>
using namespace std;
#define M 2001000
int cnt,sorted[M];
vector<pair<int,int> > len;
int il[M],ir[M],idl[M],idr[M];
int n,m;
// struct node{
//     int lc,rc;
//     int max;
// }tr[M];
// int tot;
// int change(int p,int l,int r,int li,int ri){
//     if(li<=l&&r<=ri)tr[p].max++;
//     int mid=(l+r)>>1;
//     if(li<=mid){
//         if(tr[p].lc)change(lc,l,mid)
//     }
// }


int l[4*M+1],r[4*M+1];
int sum[4*M+1],add[4*M+1];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        sum[p]=0;
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    sum[p]=max(sum[p*2],sum[p*2+1]);
}
void spread(int p){
    if(add[p]){
        sum[p*2]+=add[p];
        sum[p*2+1]+=add[p];
        add[p*2]+=add[p];
        add[p*2+1]+=add[p];
        add[p]=0;
    }
}
void change(int p,int li,int ri,int d){
    if(li<=l[p]&&ri>=r[p]){
        sum[p]+=d;
        add[p]+=d;
        return; 
    }
    spread(p);
    int mid=(l[p]+r[p])/2;
    if(li<=mid)change(p*2,li,ri,d);
    if(ri>mid)change(p*2+1,li,ri,d);
    sum[p]=max(sum[p*2],sum[p*2+1]);
}
int ask(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return sum[p];
    spread(p);
    int mid=(l[p]+r[p])/2;
    int v=0;
    if(li<=mid)v=max(v,ask(p*2,li,ri));
    if(ri>mid)v=max(v,ask(p*2+1,li,ri));
    return v;
} 

int main(){
    //freopen("P1712_17.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",il+i,ir+i);
        sorted[++cnt]=il[i];
        sorted[++cnt]=ir[i];
        len.push_back(make_pair(ir[i]-il[i],i));
    }
    
    sort(len.begin(),len.end());
    sort(sorted+1,sorted+1+n+n);
    reverse(len.begin(),len.end());
    int num=unique(sorted+1,sorted+1+n+n)-sorted-1;
    //for(auto c:sorted)
    //    printf("%d ",c);
    for(int i=1;i<=n;i++)
        idl[i]=lower_bound(sorted+1,sorted+num,il[i])-sorted;
    for(int i=1;i<=n;i++)
        idr[i]=lower_bound(sorted+1,sorted+num,ir[i])-sorted;
    int l=0,r=0;
    long long ans=(1ll<<60),now=0;
    //cout<<sorted[num]<<endl;
    build(1,1,num);
    
    //cout<<sorted[num];
    while(1){
        int mt=ask(1,1,num);
        //printf("[%d,%d]:%lld %d %lld\n",l,r,now,mt,ans);
        if(r==n&&mt<m)break;
        if(mt<m){
            r++;
            //printf("(%d:%d)",idl[len[r-1].second],idr[len[r-1].second]);
            change(1,idl[len[r-1].second],idr[len[r-1].second],1);
            now=len[l].first-len[r-1].first;
        }
        if(mt==m)ans=min(ans,now);
        if(mt>=m){
            l++;
            //printf("-(%d:%d)",idl[len[l-1].second],idr[len[l-1].second]);fflush(stdin);
            change(1,idl[len[l-1].second],idr[len[l-1].second],-1);
            now=len[l].first-len[r-1].first;
        }
    }
    if(ans>(1<<30))printf("-1");
    else printf("%lld\n",ans);
}