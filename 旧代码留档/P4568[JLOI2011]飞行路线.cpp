#include<bits/stdc++.h>
using namespace std;
#define M 2300010
int head[M],ver[M],nextt[M],wei[M],tot;
int n,m,k;
int s,t;
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
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d",&s,&t);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		for(int j=0;j<=k;j++){
			add(x+j*n,y+j*n,z);
			add(x+j*n,y+(j+1)*n,0);
			add(y+j*n,x+j*n,z);
			add(y+j*n,x+(j+1)*n,0);
		}
	}
	dijkstra();
	int ans=(1<<30);
	for(int i=0;i<=k;i++)
		ans=min(ans,d[t+i*n]);
	printf("%d\n",ans);

}