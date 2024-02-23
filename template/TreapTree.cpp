#include<bits/stdc++.h>

template<int C>
class TreapTree{
	public:
		class Node{
			public:
			int lc,rc;
			int key,pri;
			int size;
		}tree[C];
		int cnt,nroot;
	public:	
		void init(void);
		void newNode(int x);
		void updata(int p);
		void rotate(int &p,int op);
		void insert(int &p,int x);
		void del(int &p,int x);
		int rank(int p,int x);
		int findkth(int p,int k);
		int precursor(int p,int x);
		int successor(int p,int x);
};

template<int C>
void TreapTree<C>::newNode(int x){
	cnt++;
	tree[cnt].size=1;
	tree[cnt].lc=tree[cnt].rc=0;
	tree[cnt].key=x;
	tree[cnt].pri=rand();	
}

template<int C>
void TreapTree<C>::updata(int p){
	tree[p].size=tree[tree[p].lc].size+tree[tree[p].rc].size;
}

template<int C>
void TreapTree<C>::rotate(int &p,int op){
	int k;
	if(op==1){						//Left 
		k=tree[p].rc;
		tree[p].rc=tree[k].lc;
		tree[k].lc=p;
	}
	else{							//Right
		k=tree[p].lc;
		tree[p].lc=tree[k].rc;
		tree[k].rc=p;
	}
	tree[k].size=tree[p].size;
	updata(p);
	p=k;
}

template<int C>
void TreapTree<C>::insert(int &p,int x){
	if(p==0){
		newNode(x);
		p=cnt;
		return;
	}
	tree[p].size++;
	if(x>=tree[p].key)insert(tree[p].rc,x);
	else insert(tree[p].lc,x);
	if(tree[p].lc!=0&&tree[p].pri>tree[tree[p].lc].pri) rotate(p,0);
	if(tree[p].rc!=0&&tree[p].pri>tree[tree[p].rc].pri) rotate(p,1);
}

template<int C>
void TreapTree<C>::del(int &p,int x){
	tree[p].size--;
	if(tree[p].key==x){
		if(tree[p].lc==0&&tree[p].rc==0){
			p=0;
			return;
		}
		if(tree[p].lc==0||tree[p].rc==0){
			p=tree[p].lc+tree[p].rc;
			return;
		}
		if(tree[tree[p].lc].pri<tree[tree[p]].pri){
			rotate(p,0);
			del(tree[p].rs,x);
			return;
		}
		else{
			rotate(p,1);
			del(tree[p].ls,x);
			return;
		}
	}
	
	if(tree[p].key>=x)del(tree[p].lc,x);
	else del(tree[p].rc,x);
	updata(p);
}

template<int C>
int TreapTree<C>::rank(int p,int x){
	if(p==0)return 0;
	if(x>tree[p].key)return tree[tree[p].lc].size+1+rank(tree[p].rc,x);
	return rank(tree[p].lc,x);
}

template<int C>
int TreapTree<C>::findkth(int p,int k){
	if(k==tree[tree[p].lc].size+1) return tree[p].key;
	if(k>tree[tree[p].lc].size+1) return findkth(tree[p].rc,k-tree[tree[p].lc].size-1);
	if(k<=tree[tree[p].lc].size) return findkth(tree[p].lc,k);
}

template<int C>
int TreapTree<C>::precursor(int p,int x){
	if(p==0)return 0;
	if(tree[p].key>=x) return precursor(tree[p].lc,x);
	int tmp=precursor(tree[p].rc,x);
	if(tmp==0) return tree[p].key;
	return tmp;
}

template<int C>
int TreapTree<C>::successor(int p,int x){
	if(p==0)return 0;
	if(tree[p].key<=x) return successor(tree[p].rc,x);
	int tmp=successor(tree[p].lc,x);
	if(tmp==0) return tree[p].key;
	return tmp;
}
