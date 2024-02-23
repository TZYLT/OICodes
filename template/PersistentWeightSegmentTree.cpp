#include<bits/stdc++.h>
using namespace	std;
template <int C,int P>
class PersistentWeightSegmentTree{
	public:
		struct Node{
			int lc,rc,data;
		}tree[P*(int)log2(C)];
		
		int root[P],tot,data[C];
		
		PersistentWeightSegmentTree()=default;
		void init(void);
		int build(int l,int r);
		int change(int rootnow,int l,int r,int x);
		int ask(int u,int v,int l,int r,int k);
		
		friend operate();
}; 
int operate(int l,int r){
	return std::max(l,r);
}
template<int C,int P>
int PersistentWeightSegmentTree<C,P>::build(int l,int r){
	int p=++tot;
	if(l==r){
		tree[p].data=data[l];
		return p;
	}
	int mid=(l+r)>>1;
	tree[p].lc=build(l,mid);
	tree[p].rc=build(mid+1,r);
	tree[p].data=operate(tree[tree[p].lc].data,tree[tree[p].rc].data);
	
	return p;
}
 
template<int C,int P>
int PersistentWeightSegmentTree<C,P>::change(int rootnow,int l,int r,int x){
	int p=++tot;
	tree[p]=tree[rootnow];
	tree[p].data++;
	int mid=(l+r)>>1;
	if(l<r){
		if(x<=mid)tree[p].lc=change(tree[rootnow].lc,l,mid,x);
		else tree[p].rc=change(tree[rootnow].rc,mid+1,r,x);
	}
	return p;
}

template<int C,int P>
int PersistentWeightSegmentTree<C,P>::ask(int u,int v,int l,int r,int k){
	if(l==r)return l;
	int mid=(l+r)>>1,x=tree[tree[v].lc].data-tree[tree[u].lc].data;
	//printf("[%d,%d](%d %d)%d %d\n",u,v,l,r,tree[u].data,tree[v].data);
	if(x>=k)
		return ask(tree[u].lc,tree[v].lc,l,mid,k);
	else return ask(tree[u].rc,tree[v].rc,mid+1,r,k-x);
}

PersistentWeightSegmentTree<200100,200100> tr;
int n,m,in[200100],s[200100];

int main(){
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&in[i]);
		s[i]=in[i];
	}
	sort(s+1,s+n+1);
	int size=unique(s+1,s+n+1)-s-1;
	for(int i=1;i<=n;i++){
		int x=lower_bound(s+1,s+1+size,in[i])-s;
		tr.root[i]=tr.change(tr.root[i-1],1,size,x);
		//printf("[%d]:%d",x,in[i]);
	}
	while(m--){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		printf("%d\n",s[tr.ask(tr.root[x-1],tr.root[y],1,size,k)]);
	}	
	cout<<(sizeof(tr)>>20)<<"MB";
}
