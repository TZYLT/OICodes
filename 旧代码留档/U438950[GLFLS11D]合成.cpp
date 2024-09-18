#include<bits/stdc++.h>
using namespace std;
#define M 400200
int n,m;
int x[M],y[M],z[M],tt[M];
long long f[M],v[M];
vector<int> edge[M];
priority_queue<pair<long long,int> > q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",x+i,y+i,z+i,tt+i);
		if(x[i]!=y[i])edge[x[i]].push_back(i),edge[y[i]].push_back(i);
		else edge[x[i]].push_back(i);
	}
		
	
	memset(f,0x3f,sizeof(f));
	f[1]=0;

	q.push(make_pair(0,1));
	while(q.size()){
		int t=q.top().second;q.pop();
        if(v[t])continue;
        v[t]=1;
		for(auto c:edge[t]){
			long long l=f[z[c]];
			f[z[c]]=min(f[z[c]],max(f[x[c]],f[y[c]])+tt[c]);
			//printf("[%d(%d),%d(%d)]->%d(%d)\n",x[c],f[x[c]],y[c],f[y[c]],z[c],f[z[c]]);
			if(l!=f[z[c]])q.push(make_pair(-f[z[c]],z[c]));
		}
	}
	printf("%lld\n",f[n]);
	return 0;
	
}

// #include<bits/stdc++.h>
// using namespace std;
// #define M 400200
// int n,m;
// int head[M],nextt[M],edge[M],ver[M],cnt;
// void add(int x,int y,int z){
//     ++cnt;
//     ver[cnt]=y;
//     edge[cnt]=z;
//     nextt[cnt]=head[x];
//     head[x]=cnt;
// }


// long long v[M],d[M];
// priority_queue<pair<int,int> > q;
// void dijkstra(){
//     memset(d,0x3f,sizeof(d));
//     memset(v,0,sizeof(v));
//     d[1]=0;
//     q.push(make_pair(0,1));
//     while(q.size()){
//         int x=q.top().second;
//         q.pop();
//         if(v[x])continue;
//         v[x]=1;
//         for(int i=head[x];i;i=nextt[i]){
//             int y=ver[i],z=edge[i];
//             if(d[y]>d[x]+z){
//                 d[y]=d[x]+z;
//                 q.push(make_pair(-d[y],y));
//             }
//         }
//     }
// }

// int main(){
//     scanf("%d%d",&n,&m);
// 	for(int i=1,x,y,z,t;i<=m;i++){
// 		scanf("%d%d%d%d",&x,&y,&z,&t);
//         add(x,z,t);
//         add(y,z,t);
// 	}
    
// }