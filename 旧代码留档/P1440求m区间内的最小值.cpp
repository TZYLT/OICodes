#include<bits/stdc++.h>

template <int C>
class SegmentTree{
	public:
		int l[4*C+1],r[4*C+1];
		long long sum[4*C+1],add[4*C+1];
		int data[C+1];
		
		SegmentTree(){init();}
		void init(void);
		void build(int p,int li,int ri);
		void spread(int p);
		void change(int p,int li,int ri,int d);
		int ask(int p,int li,int ri);
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
	sum[p]=std::min(sum[p*2],sum[p*2+1]);
}

template <int C>
int SegmentTree<C>::ask(int p,int li,int ri){
	if(li<=l[p]&&ri>=r[p]) return sum[p];
	int mid=(l[p]+r[p])/2;
	int v=(1<<30);
	if(li<=mid)v=std::min(ask(p*2,li,ri),v);
	if(ri>mid)v=std::min(ask(p*2+1,li,ri),v);
	return v;
} 

int n,m;
SegmentTree<2000100> t;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&t.data[i]);
	t.build(1,1,n);
	printf("0\n");
	for(int i=2;i<=n;i++){
		printf("%d\n",t.ask(1,i-m<1?1:i-m,i-1));
	}
}
