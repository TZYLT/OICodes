#include<bits/stdc++.h>
using namespace std;
template <int C>
class SegmentTree{
	public:
		int l[4*C+1],r[4*C+1];
		long long sum[4*C+1];
		long long data[C+1];
		int no[4*C+1];
		SegmentTree()=default;
		void init(void);
		void build(int p,int li,int ri);
		void spread(int p);
		void change(int p,int li,int ri);
		long long ask(int p,int li,int ri);
}; 
 
template <int C>
void SegmentTree<C>::init(void){
	for(int i=1;i<=C;i++) data[i]=0,l[i]=0,r[i]=0,sum[i]=0;
	//build(1,1,n);
}

template <int C>
void SegmentTree<C>::build(int p,int li,int ri){
	l[p]=li;r[p]=ri;
	if(li==ri){
		sum[p]=data[li];
		no[p]=1;
		return;
	}
	int mid=(li+ri)/2;
	build(p*2,li,mid);
	build(p*2+1,mid+1,ri);
	sum[p]=sum[p*2]+sum[p*2+1];
	no[p]=no[p*2]+no[p*2+1];
}

template <int C>
void SegmentTree<C>::change(int p,int li,int ri){
	//printf("[%d](%d,%d)NO:%d SUM:%d\n",p,l[p],r[p],no[p],sum[p]);
	if(li<=l[p]&&ri>=r[p]&&no[p]==0){return;}
	//if(l[p]==0||r[p]==0)return;
	if(li<=l[p]&&ri>=r[p]&&l[p]==r[p]){
		sum[p]=(long long)sqrt(sum[p]);
		if(sum[p]==1)no[p]=0;
		return;
	}
	int mid=(l[p]+r[p])/2;
	if(li<=mid)change(p*2,li,ri);
	if(ri>mid)change(p*2+1,li,ri);
	sum[p]=sum[p*2]+sum[p*2+1];
	no[p]=no[p*2]+no[p*2+1];
}

template <int C>
long long SegmentTree<C>::ask(int p,int li,int ri){
	//printf("[%d](%d,%d)SUM:%d\n",p,l[p],r[p],sum[p]);
	if(li<=l[p]&&ri>=r[p]) return sum[p];
	int mid=(l[p]+r[p])/2;
	long long v=0;
	if(li<=mid)v+=ask(p*2,li,ri);
	if(ri>mid)v+=ask(p*2+1,li,ri);
	return v;
} 
int n,m,l,r,op;
SegmentTree<400100> tr;
int main(){
	tr.init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&tr.data[i]);
	tr.build(1,1,n);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&op,&l,&r);
		if(l>r)swap(l,r);
		if(op==0) tr.change(1,l,r);
		else printf("%lld\n",tr.ask(1,l,r));
	}
}
