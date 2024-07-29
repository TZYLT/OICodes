#include<bits/stdc++.h>
using namespace std;
template<int C>
class TreapTree{
	public:
		class Node{
			public:
			int lc,rc;
			int key,pri;
			int size;
		};
		vector<Node> tree;
		int cnt,nroot=0;
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
void TreapTree<C>::init(void){
	tree.push_back((Node){0,0,0,0,0});
	tree.resize(200);
}
template<int C>
void TreapTree<C>::newNode(int x){
	tree.push_back((Node){0,0,0,0,0});
	cnt++;
	tree[cnt].size=1;
	tree[cnt].lc=tree[cnt].rc=0;
	tree[cnt].key=x;
	tree[cnt].pri=rand();	
}

template<int C>
void TreapTree<C>::updata(int p){
	tree[p].size=tree[tree[p].lc].size+tree[tree[p].rc].size+1;
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
	updata(p);
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
		if(tree[tree[p].lc].pri<tree[tree[p].rc].pri){
			rotate(p,0);
			del(tree[p].rc,x);
			return;
		}
		else{
			rotate(p,1);
			del(tree[p].lc,x);
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
	if(k<=tree[tree[p].lc].size)return findkth(tree[p].lc,k);
}

template<int C>
int TreapTree<C>::precursor(int p,int x){
	if(p==0)return -2147483647;
	if(tree[p].key>=x) return precursor(tree[p].lc,x);
	int tmp=precursor(tree[p].rc,x);
	if(tmp==0) return tree[p].key;
	return tmp;
}

template<int C>
int TreapTree<C>::successor(int p,int x){
	if(p==0)return 2147483647;
	if(tree[p].key<=x) return successor(tree[p].rc,x);
	int tmp=successor(tree[p].lc,x);
	if(tmp==0) return tree[p].key;
	return tmp;
}
struct seg{
	int l,r;
	TreapTree<50050> tr;
	void init(void){
		tr.insert(tr.nroot,-2147483647);
		tr.insert(tr.nroot,2147483647);
	}
};

seg tr[200200];

void build(int p,int l,int r){
	tr[p].l=l;tr[p].r=r;tr[p].tr.init();
	if(l==r)return;
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build((p<<1)|1,mid+1,r);
}
void insert(int p,int d,int x){
	tr[p].tr.insert(tr[p].tr.nroot,x);
	if(tr[p].l==d&&d==tr[p].r){return;}
		
	int mid=(tr[p].l+tr[p].r)>>1;
	if(d<=mid)insert(p<<1,d,x);
	else insert((p<<1)|1,d,x);
}
void del(int p,int d,int x){
	tr[p].tr.del(tr[p].tr.nroot,x);
	if(tr[p].l==d&&d==tr[p].r)return;
		
	int mid=(tr[p].l+tr[p].r)>>1;
	if(d<=mid)del(p<<1,d,x);
	else del((p<<1)|1,d,x);
}
int Rank(int p,int l,int r,int x){
	if(l<=tr[p].l&&tr[p].r<=r)
		return tr[p].tr.rank(tr[p].tr.nroot,x)+1;
	int mid=(tr[p].l+tr[p].r)>>1;
	int ans=0;
	if(l<=mid)ans+=Rank(p<<1,l,r,x);
	if(r>mid)ans+=Rank((p<<1)|1,l,r,x);
	return ans;
}
int kth(int nl,int nr,int l,int r,int k){
	if(nl==nr)return nl;
	int mid=(nl+nr)>>1;
	int ans=Rank(1,l,r,mid);
	if(ans>k)return kth(nl,mid,l,r,k);
	else return kth(mid+1,nr,l,r,k);
}
int pre(int p,int l,int r,int x){
	if(l<=tr[p].l&&tr[p].r<=r)
		return tr[p].tr.precursor(tr[p].tr.nroot,x);
	int mid=(tr[p].l+tr[p].r)>>1;
	int ans=(-2147483647);
	if(l<=mid)ans=max(pre(p<<1,l,r,x),ans);
	if(r>mid)ans=max(pre((p<<1)|1,l,r,x),ans);
	return ans;
}
int sur(int p,int l,int r,int x){
	if(l<=tr[p].l&&tr[p].r<=r)
		return tr[p].tr.successor(tr[p].tr.nroot,x);
	int mid=(tr[p].l+tr[p].r)>>1;
	int ans=2147483647;
	if(l<=mid)ans=min(sur(p<<1,l,r,x),ans);
	if(r>mid)ans=min(sur((p<<1)|1,l,r,x),ans);
	return ans;
}
int n,m;
int data[50050];
int main(){
	srand(time(0));
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]),insert(1,i,data[i]);
	while(m--){
		int op,x,y,z;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&x,&y,&z);
			printf("%d\n",Rank(1,x,y,z));
		}else if(op==2){
			scanf("%d%d%d",&x,&y,&z);
			printf("%d\n",kth(0,1e8,x,y,z));
		}else if(op==3){
			scanf("%d%d",&x,&y);
			del(1,x,data[x]);
			insert(1,x,y);
			data[x]=y;
		}else if(op==4){
			scanf("%d%d%d",&x,&y,&z);
			printf("%d\n",pre(1,x,y,z));
		}else{
			scanf("%d%d%d",&x,&y,&z);
			printf("%d\n",sur(1,x,y,z));
		}
	}
}