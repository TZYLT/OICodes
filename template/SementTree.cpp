#include<bits/stdc++.h>

template <int C>
class SegmentTree{
	public:
		int l[4*C+1],r[4*C+1];
		long long sum[4*C+1],add[4*C+1];
		int data[C+1];
		
		SegmentTree()=default;
		void init(void);
		void build(int p,int li,int ri);
		void spread(int p);
		void change(int p,int li,int ri,int d);
		long long ask(int p,int li,int ri);
}; 
 
 
template <int C>
void SegmentTree<C>::init(void){
	for(int i=1;i<=C;i++) data[i]=0,l[i]=0,r[i]=0,sum[i]=0,add[i]=0;
	//build(1,1,n);
}

template <int C>
void SegmentTree<C>::build(int p,int li,int ri){
	l[p]=li;r[p]=ri;
	if(li==ri){
		sum[p]=data[li];
		return;
	}
	int mid=(li+ri)/2;
	build(p*2,li,mid);
	build(p*2+1,mid+1,ri);
	sum[p]=sum[p*2]+sum[p*2+1];
}

template <int C>
void SegmentTree<C>::spread(int p){
	if(add[p]){
		sum[p*2]+=add[p]*(r[p*2]-l[p*2]+1);
		sum[p*2+1]+=add[p]*(r[p*2+1]-l[p*2+1]+1);
		add[p*2]+=add[p];
		add[p*2+1]+=add[p];
		add[p]=0;
	}
}

template <int C>
void SegmentTree<C>::change(int p,int li,int ri,int d){
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

template <int C>
long long SegmentTree<C>::ask(int p,int li,int ri){
	if(li<=l[p]&&ri>=r[p]) return sum[p];
	spread(p);
	int mid=(l[p]+r[p])/2;
	long long v=0;
	if(li<=mid)v+=ask(p*2,li,ri);
	if(ri>mid)v+=ask(p*2+1,li,ri);
	return v;
	
} 
