#include<bits/stdc++.h>
using namespace std;
#define M (1<<24)+1
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int v[M],d[M];
priority_queue<pair<int,int> > q;
void dijkstra(int s){
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
            int y=ver[i],z=edge[i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}
int n,m;
int b1[M],b2[M],k1[M],k2[M],c[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        string s,t;
        cin>>c[i]>>s>>t;
        for(int j=1;j<=n;j++){
            b1[i]<<=1;b2[i]<<=1;
            if(s[j-1]=='+') b1[i]|=1;
            else if(s[j-1]=='-') b2[i]|=1;
        }

        for(int j=1;j<=n;j++){
            k1[i]<<=1;k2[i]<<=1;
            if(t[j-1]=='-') k1[i]|=1;
            else if(t[j-1]=='+') k2[i]|=1;
        }
    }
    for(int i=0;i<(1<<n);i++)
        for(int j=1;j<=m;j++)
            if(((i&b1[j])==b1[j])&&((i&b2[j])==0))
                add(i+1,(((i&k1[j])^i)|k2[j])+1,c[j]);
    dijkstra((1<<n));
    if(d[1]!=0x3f3f3f3f)printf("%d\n",d[1]);
    else printf("0\n");
}