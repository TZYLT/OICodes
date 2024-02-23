#include<bits/stdc++.h>

template <int C,int P>
class PersistentSementTree{
	public:
		struct Node{
			int lc,rc,data;
		}tree[P*(int)log2(C)];
		
		int root[P],tot,data[C];
		
		PersistentSementTree()=default;
		void init(void);
		int build(int l,int r);
		int change(int rootnow,int l,int r,int x,int d);
		friend operate();
}; 
int operate(int l,int r){
	return std::max(l,r);
}
template<int C,int P>
int PersistentSementTree<C,P>::build(int l,int r){
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
int PersistentSementTree<C,P>::change(int rootnow,int l,int r,int x,int d){
	int p=++tot;
	tree[p]=tree[rootnow];
	if(l==r){
		tree[p].data=d;
		return p;
	}
	int mid=(l+r)>>1;
	if(x<=mid)tree[p].lc=change(tree[rootnow].lc,l,mid,x,d);
	else tree[p].rc=change(tree[rootnow].rc,mid+1,r,x,d);
	tree[p].data=operate(tree[tree[p].lc].data,tree[tree[p].rc].data);
	return p;
}
