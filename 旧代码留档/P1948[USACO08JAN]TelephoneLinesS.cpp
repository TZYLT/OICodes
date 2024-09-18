#include<bits/stdc++.h>
using namespace std;
#define M 200200
int head[M],ver[M],nextt[M],wei[M],tot;
const int s=1;
void add(int x,int y,int z){
	ver[++tot]=y;
	wei[tot]=z;
	nextt[tot]=head[x];
	head[x]=tot;
}
int v[M],d[M];
priority_queue<pair<int,int> > q;
void dijkstra(int in){
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	while(q.size())q.pop();
	
	d[s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=nextt[i]){
			int y=ver[i],z=wei[i]>in?1:0;
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}

int n,p,k;
int search(int l,int r){
	if(l==r)return l;
	int mid=(l+r)>>1;
	dijkstra(mid);
	if(d[n]>k)return search(mid+1,r);
	else if(d[n]<=k)return search(l,mid);
}

int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=p;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dijkstra(0);
	if(d[n]>2000000){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",search(0,10000000));

}