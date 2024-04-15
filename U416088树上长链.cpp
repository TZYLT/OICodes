#include<bits/stdc++.h>
using namespace std;
#define M 2001000
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
inline int read() {
	int x = 0;
    bool f=0;
	char c = getchar();
	while(!isdigit(c)){
		if(c=='-')f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
int d[M],md[M],ms[M],p[M],ans[M];
void dfs1(int x,int fa){
    d[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs1(ver[i],x);
            d[x]=max(d[x],d[ver[i]]+1);
            if(d[md[x]]<d[ver[i]])
                md[x]=ver[i];
        }
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa&&ver[i]!=md[x])
            ms[x]=max(ms[x],d[ver[i]]);
}
void dfs2(int x,int fa){
    p[x]=p[fa]+1;
    if(fa!=0)
        if(x==md[fa]) p[x]=max(p[x],ms[fa]+2);
        else p[x]=max(p[x],d[md[fa]]+2);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)dfs2(ver[i],x);
    ans[x]=max(p[x]+d[x]-1,ms[x]+d[md[x]]+1)-1;
    //printf("[%d]:d:%d md:%d ms:%d p:%d ans:%d\n",x,d[x],md[x],ms[x],p[x],ans[x]);
}
int x,n;
int main(){
    n=read();
    for(int i=1;i<n;i++){
        x=read();
        add(x,i);
        add(i,x);
    }
    dfs1(1,0);
    dfs2(1,0);
    long long a=0;
    for(int i=1;i<=n;i++)
        a=(a+(long long)i*ans[i])%998244353;

    printf("%lld\n",a);
}