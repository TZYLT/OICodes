#include<bits/stdc++.h>
using namespace std;

template <int C>
struct SegmentTree{
    int l[4*C+1],r[4*C+1];
    int tag1[4*C+1],tag2[4*C+1],pre[4*C+1],pt[4*C+1],ft[4*C+1],fix[4*C+1],len[4*C+1],sum[4*C+1];
    int data[C+1];
    void build(int p,int li,int ri){
        l[p]=li;r[p]=ri;
        if(li==ri){
            sum[p]=data[li];
            fix[p]=pre[p]=len[p]=1;
            tag1[p]=0;pt[p]=ft[p]=data[li];
            return;
        }
        int mid=(li+ri)/2;
        build(p*2,li,mid);
        build(p*2+1,mid+1,ri);
        sum[p]=sum[p*2]+sum[p*2+1];
        len[p]=max(len[p*2],max(len[p*2+1],
                (ft[p*2]==pt[p*2])?(fix[p*2]+pre[p*2+1])));
        pt[p]=pr[p*2];
        ft[p]=ft[p*2+1];
        pre[p]=pre[p*2];
        fix[p]=fix[p*2+1];
    }
    void spread1(int p){
        if(tag1[p]){
            pt[p*2]=pt[p*2]^1;
            pt[p*2+1]=pt[p*2+1]^1;
            ft[p*2]=ft[p*2]^1;
            ft[p*2+1]=ft[p*2+1]^1;
            sum[p*2]=r[p*2]-l[p*2]+1-sum[p*2];
            sum[p*2+1]=r[p*2+1]-l[p*2+1]+1-sum[p*2+1];
            tag1[p*2]=tag1[p*2+1]=1;
            tag1[p]=0;
        }
    }
    void spread2(int p){
        if(tag!=-1){
            
        }
    }
    void changeall(int p,int li,int ri,int d){
        if(li<=l[p]&&ri>=r[p]){
            
        }
    }
    void change(int p,int li,int ri,int d){
        if(li<=l[p]&&ri>=r[p]){
            sum[p]+=(long long)d*(r[p]-l[p]+1);
            add[p]+=d;
            return; 
        }
        spread(p);
        int mid=(l[p]+r[p])/2;
        if(li<=mid)change(p*2,li,ri,d);
        if(ri>mid)change(p*2+1,li,ri,d);
        sum[p]=sum[p*2]+sum[p*2+1];
    }
    long long :ask(int p,int li,int ri){
        if(li<=l[p]&&ri>=r[p]) return sum[p];
        spread(p);
        int mid=(l[p]+r[p])/2;
        long long v=0;
        if(li<=mid)v+=ask(p*2,li,ri);
        if(ri>mid)v+=ask(p*2+1,li,ri);
        return v;
    } 
};