#include<bits/stdc++.h>

#include<bits/stdc++.h>

template <int C>
struct SegmentTree{
	int l[4*C+1],r[4*C+1];
	//data
    //tag
    //info
    void init(void){
        for(int i=1;i<=C;i++) 
            data[i]=0,l[i]=0,r[i]=0,sum[i]=0,add[i]=0;
    }
    void build(int p,int li,int ri){
        l[p]=li;r[p]=ri;
        if(li==ri){
            //one dot
            return;
        }
        int mid=(li+ri)/2;
        build(p*2,li,mid);
        build(p*2+1,mid+1,ri);
        //updata
    }
    void spread(int p){
        //pushdown
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