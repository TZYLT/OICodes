#include<bits/stdc++.h>

template <int C>
class DisjointSet{
	public:
	int fa[C];
	
	DisjointSet()=default;
	DisjointSet& inti(void);
	int get(int x);
	void merge(int x,int y); 
};

template<int C>
DisjointSet<C>& DisjointSet<C>::inti(void){
	for(int i=0;i<C;i++)
			fa[i]=i; 
		return *this;
}

template<int C>
int DisjointSet<C>::get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
} 

template<int C>
void DisjointSet<C>::merge(int x,int y){
	fa[get(x)]=get(y);
}
