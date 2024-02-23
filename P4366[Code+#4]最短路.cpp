#include<bits/stdc++.h>
using namespace std;
#define M 4500010
int head[M],ver[M],nextt[M],wei[M],tot;
int n,m,c,s,t;
void add(int x,int y,int z){
	ver[++tot]=y;
	wei[tot]=z;
	nextt[tot]=head[x];
	head[x]=tot;
}
int v[M],d[M];
priority_queue<pair<int,int> > q;
void dijkstra(){
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=nextt[i]){
			int y=ver[i],z=wei[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++){
		for(int j=0;(1<<j)<=i;j++){
			add(i,i^(1<<j),(1<<j)*c);
			add(i^(1<<j),i,(1<<j)*c);
			//printf("[DEBUG]:(%d->%d:%d)\n",i,i^(1<<j),1<<j);
		}
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	scanf("%d%d",&s,&t);
	dijkstra();
	printf("%d\n",d[t]);
}