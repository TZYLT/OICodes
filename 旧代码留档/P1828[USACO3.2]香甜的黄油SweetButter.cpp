#include<bits/stdc++.h>
using namespace std;
#define M 10010

long long head[M],nextt[M],eage[M],ver[M],cnt;
void add(long long x,long long y,long long z){
    ++cnt;
    ver[cnt]=y;
    eage[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}

long long v[M],d[M];
priority_queue<pair<long long,long long> > q;
void dijkstra(int s){
    while(!q.empty())q.pop();
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		long long x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=nextt[i]){
			long long y=ver[i],z=eage[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}
long long n,p,c;
long long w[M];
int main(){
    scanf("%d%d%d",&n,&p,&c);
    for(int i=1;i<=n;i++){
        long long t;
        scanf("%lld",&t);
        w[t]++;
    }
    for(int i=1;i<=c;i++){
        long long x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    long long ans=(1<<30);
    for(int i=1;i<=p;i++){
        dijkstra(i);

        long long t=0;
        for(int j=1;j<=p;j++)
            t+=d[j]*w[j];
        ans=min(abs(ans),abs(t));
    }
    printf("%lld\n",ans);
}