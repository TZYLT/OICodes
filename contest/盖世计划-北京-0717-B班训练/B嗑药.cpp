#include<bits/stdc++.h>
using namespace std;
long long l,a,b,t,r,n,x;
#define M 1000000
int head[M],nextt[M],ver[M],cnt;
double edge[M];
void add(int x,int y,double z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
struct pr{
	long long first,second;
	friend bool operator< (pr x,pr y){return x.first==y.first?x.second<y.second:x.first<y.first;}
	friend bool operator== (pr x,pr y){return x.first==y.first&&x.second==y.second;}
};
vector<pr> dot;
queue<int> q;
double dis[M];int v[M];
long long sp[M];
int main(){
    scanf("%lld%lld%lld%lld%lld",&l,&a,&b,&t,&r);
    scanf("%lld",&n);
    dot.push_back((pr){0,0});
    for(int i=1;i<=n;i++){
        scanf("%lld",sp+i);
        dot.push_back((pr){sp[i],1});
        if(sp[i]+a*t+b*r<l)dot.push_back((pr){sp[i]+a*t+b*r,0});
    }
    dot.push_back((pr){l,2});
    sort(dot.begin(),dot.end());
    int cnt=unique(dot.begin(),dot.end())-dot.begin();
    for(int i=0;i<cnt;i++){
        if(dot[i].second==0)add(i+1,i+2,(double)(dot[i+1].first-dot[i].first)/a);
        else if(dot[i].second==1){
            add(i+1,i+2,(double)(dot[i+1].first-dot[i].first)/a);
            
            if(sp[i]+a*t+b*r<l){
				int id=lower_bound(dot.begin(),dot.end(),(pr){sp[i]+a*t+b*r,0})-dot.begin();
				add(i+1,id+1,t+r);
			}else{
				if(dot[i].first+a*t>=l)add(i+1,cnt,(double)(l-dot[i].first)/a);
				else if(dot[i].first+a*t+b*r>=l)add(i+1,cnt,(double)(l-dot[i].first-a*t)/b+(double)t);
			}
            int idn=lower_bound(dot.begin(),dot.end(),(pr){sp[i+1]+a*t,0})-dot.begin();
            if(dot[i].first+a*t+b*r>dot[idn].first)add(i+1,idn+1,(double)(dot[idn].first-dot[i].first-a*t)/b+(double)t);
        }
    }

	for(int i=0;i<=cnt;i++)dis[i]=1e18;
    q.push(1);dis[1]=0;
    while(q.size()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=nextt[i]){
			dis[ver[i]]=min(dis[ver[i]],dis[x]+edge[i]);
			if(v[ver[i]]==0)q.push(ver[i]),v[ver[i]]=1;
		}
	}
	
	printf("%.3lf\n",dis[cnt]);
	return 0;
	
}
