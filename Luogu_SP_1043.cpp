#include<cstdio>
#include<algorithm>
using namespace std;
#define N 500001
struct Node{int mv,ml,mr,sv;}tree[N<<2];
void pushup(Node &rt,const Node &ls,const Node &rs){
	if(ls.mr<0 && rs.ml<0)rt.mv=max(ls.mr,rs.ml);
	else{
	  	rt.mv=0;
	  	if(ls.mr>0)rt.mv+=ls.mr;
	  	if(rs.ml>0)rt.mv+=rs.ml;
	}
	rt.mv=max(rt.mv,ls.mv);
	rt.mv=max(rt.mv,rs.mv);
	rt.ml=max(ls.ml,ls.sv+rs.ml);
	rt.mr=max(rs.mr,rs.sv+ls.mr);
	rt.sv=ls.sv+rs.sv;
}
void buildtree(int rt,int l,int r){
	if(l==r){
	  	scanf("%d",&tree[rt].mv);
	  	tree[rt].sv=tree[rt].ml=tree[rt].mr=tree[rt].mv;
	  	return;
	}
	int m=(l+r)/2;
	buildtree(rt*2,l,m);
	buildtree(rt*2+1,m+1,r);
	pushup(tree[rt],tree[rt*2],tree[rt*2+1]);
}
void update(int p,int v,int rt,int l,int r){
	if(l==r){
	  	tree[rt].sv=tree[rt].ml=tree[rt].mr=tree[rt].mv=v;
	  	return;
	}
	int m=(l+r)/2;
	if(p<=m) update(p,v,rt*2,l,m);
	else update(p,v,rt*2+1,m+1,r);
	pushup(tree[rt],tree[rt*2],tree[rt*2+1]);
}
Node query(int ql,int qr,int rt,int l,int r){
	if(ql<=l&&r<=qr) return tree[rt];
	int m=(l+r)/2;
	if(ql<=m && m<qr){
	  	Node res;
	  	pushup(res,query(ql,qr,rt*2,l,m),query(ql,qr,rt*2+1,m+1,r));
	  	return res;
	}
	else if(ql<=m) return query(ql,qr,rt*2,l,m);
	else return query(ql,qr,rt*2+1,m+1,r);
}
int n,m;
int main(){
	int x,y;
	scanf("%d",&n);
	buildtree(1,1,n);
    scanf("%d",&m);
	while(m--){
	  	scanf("%d%d",&x,&y);
	  	if(x>y)swap(x,y);
	  	printf("%d\n",query(x,y,1,1,n).mv);
	}
	return 0;
}