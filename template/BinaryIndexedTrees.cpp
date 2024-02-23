#include<bits/stdc++.h>

template <int C>
class BinaryIndexedTrees{
	public:
		int data[C+1],c[C+1];
		BinaryIndexedTrees()=default;
		void inti(void);
		int ask(int x);
		void add(int x,int d);
};

template<int C>
int BinaryIndexedTrees<C>::ask(int x){
	int ans=0;
	for(;x;x-=x&-x)ans+=c[x];
	return ans;
}

template<int C>
void BinaryIndexedTrees<C>::add(int x,int d){
	for(;x<=C;x+=x&-x) c[x]+=d; 
}

template<int C>
void BinaryIndexedTrees<C>::inti(void){
	for(int i=1;i<=C;i++) data[i]=c[i]=0;
}
