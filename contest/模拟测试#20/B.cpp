#include<bits/stdc++.h>
using namespace std;
long long sum;
int n,q;

template<int C>
class TreapTree{
	public:
		class Node{
			public:
			int lc,rc;
			long long size,sum,key,pri;
		}tree[C];
		int cnt,nroot;
	public:	
		void newNode(long long x);
		void updata(int p);
		void rotate(int &p,int op);
		void insert(int &p,long long x);
		void del(int &p,long long x);
		long long kthsum(int p,int k);
		int ranksum(int p,long long x);
};

template<int C>
void TreapTree<C>::newNode(long long x){
	cnt++;
	tree[cnt].size=1;
	tree[cnt].lc=tree[cnt].rc=0;
	tree[cnt].key=x;
	tree[cnt].sum=x;
	tree[cnt].pri=rand();	
}

template<int C>
void TreapTree<C>::updata(int p){
	tree[p].size=tree[tree[p].lc].size+tree[tree[p].rc].size+1;
	tree[p].sum=tree[tree[p].lc].sum+tree[tree[p].rc].sum+tree[p].key;
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
void TreapTree<C>::insert(int &p,long long x){
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
void TreapTree<C>::del(int &p,long long x){
	tree[p].size--;
	if(tree[p].key==x){
		if(tree[p].lc==0&&tree[p].rc==0){
			p=0;
			tree[p].sum=tree[tree[p].lc].sum+tree[tree[p].rc].sum+tree[p].key;
			return;
		}
		if(tree[p].lc==0||tree[p].rc==0){
			p=tree[p].lc+tree[p].rc;
			tree[p].sum=tree[tree[p].lc].sum+tree[tree[p].rc].sum+tree[p].key;
			return;
		}
		if(tree[tree[p].lc].pri<tree[tree[p].rc].pri){
			rotate(p,0);
			del(tree[p].rc,x);
			tree[p].sum=tree[tree[p].lc].sum+tree[tree[p].rc].sum+tree[p].key;
			return;
		}
		else{
			rotate(p,1);
			del(tree[p].lc,x);
			tree[p].sum=tree[tree[p].lc].sum+tree[tree[p].rc].sum+tree[p].key;
			return;
		}
	}
	
	if(tree[p].key>=x)del(tree[p].lc,x);
	else del(tree[p].rc,x);
	updata(p);
}

template<int C>
int TreapTree<C>::ranksum(int p,long long x){
	if(p==0)return 0;
	if(x>tree[tree[p].lc].sum+tree[p].key)
        return tree[tree[p].lc].size+1+ranksum(tree[p].rc,x-tree[tree[p].lc].sum-tree[p].key);
	if(x>tree[tree[p].lc].sum&&x<tree[tree[p].lc].sum+tree[p].key)
        return tree[tree[p].lc].size+1;
	if(x<tree[tree[p].lc].sum)
        return ranksum(tree[p].lc,x);
}

template<int C>
long long TreapTree<C>::kthsum(int p,int k){
	if(p==0)return 0;
	if(k==tree[tree[p].lc].size+1)
        return tree[tree[p].lc].sum+tree[p].key;
	if(k>tree[tree[p].lc].size+1)
        return tree[tree[p].lc].sum+tree[p].key+kthsum(tree[p].rc,k-tree[tree[p].lc].size-1);
	if(k<tree[tree[p].lc].size)
        return kthsum(tree[p].lc,k);
}
TreapTree<1501000> tr;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        if(x>0)
            tr.insert(tr.nroot,x);
        if(x<0)
            sum-=x;
    }
    while(q--){
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==1){
            if(x>0)
                tr.insert(tr.nroot,x);
            else
                sum-=x;
        }else{
            if(x>0)
                tr.del(tr.nroot,x);
            else
                sum+=x;
        }
        printf("%d\n",tr.ranksum(tr.nroot,sum)+1);
    }

}