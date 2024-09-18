#include<bits/stdc++.h>
using namespace std;
template <int C>
class SegmentTree{
	public:
		int l[4*C+1],r[4*C+1];
		long long sum[4*C+1],add[4*C+1];
		int maxx[4*C+1];
		int data[C+1];
		
		SegmentTree()=default;
		void init(void);
		void build(int p,int li,int ri);
		void spread(int p);
		void change_mod(int p,int li,int ri,int d);
		long long ask(int p,int li,int ri);
		int ask_max(int p,int li,int ri);
		void change_add(int p,int x,int d);
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
		maxx[p]=data[li];
		sum[p]=data[li];
		return;
	}
	int mid=(li+ri)/2;
	build(p*2,li,mid);
	build(p*2+1,mid+1,ri);
	sum[p]=sum[p*2]+sum[p*2+1];
	maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}

template <int C>
void SegmentTree<C>::change_mod(int p,int li,int ri,int d){
	if(maxx[p]<d)return;
	if(li<=l[p]&&ri>=r[p]&&l[p]==r[p]){
		sum[p]%=d;
		maxx[p]=sum[p];
		return; 
	}
	int mid=(l[p]+r[p])/2;
	if(li<=mid)change_mod(p*2,li,ri,d);
	if(ri>mid)change_mod(p*2+1,li,ri,d);
	sum[p]=sum[p*2]+sum[p*2+1];
	maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}

template <int C>
void SegmentTree<C>::change_add(int p,int x,int d){
	if(l[p]==r[p]&&l[p]==x){
		sum[p]=d;
		maxx[p]=d;
		return; 
	}
	int mid=(l[p]+r[p])/2;
	if(x<=mid)change_add(p*2,x,d);
	if(x>mid)change_add(p*2+1,x,d);
	sum[p]=sum[p*2]+sum[p*2+1];
	maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
template <int C>
long long SegmentTree<C>::ask(int p,int li,int ri){
	if(li<=l[p]&&ri>=r[p]) return sum[p];
	int mid=(l[p]+r[p])/2;
	long long v=0;
	if(li<=mid)v+=ask(p*2,li,ri);
	if(ri>mid)v+=ask(p*2+1,li,ri);
	return v;
} 

template <int C>
int SegmentTree<C>::ask_max(int p,int li,int ri){
	if(li<=l[p]&&ri>=r[p]) return maxx[p];
	int mid=(l[p]+r[p])/2;
	int v=-1;
	if(li<=mid)v=max(ask(p*2,li,ri),v);
	if(ri>mid)v=max(ask(p*2+1,li,ri),v);
	return v;
} 
int n,m,l,r,k,op;
SegmentTree<400100> tr;
int main(){
	tr.init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&tr.data[i]);
	tr.build(1,1,n);
	while(m--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&l,&r);
			printf("%lld\n",tr.ask(1,l,r));
		}else if(op==2){
			scanf("%d%d%d",&l,&r,&k);
			tr.change_mod(1,l,r,k);
		}else {
			scanf("%d%d",&l,&k);
			tr.change_add(1,l,k);
		}
	}
}
