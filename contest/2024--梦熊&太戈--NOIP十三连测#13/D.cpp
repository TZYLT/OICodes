#include<bits/stdc++.h>
using namespace std;
int n,a[100100];
struct node{
    int w,c;	
}tr[100100];
int rt[100100];
int cnt;
int merge(int x,int y){
    ++cnt;
	tr[cnt].c=tr[x].c+tr[y].c;
    tr[cnt].w=tr[x].w+tr[y].w+tr[y].c+tr[y].c+tr[x].c;
    return cnt;
}
priority_queue<pair<int,int> > q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
		tr[i].w=tr[i].c=a[i],q.push({-a[i],i});
	while(q.size()>=2){
		int x=q.top().second;q.pop();
		int y=q.top().second;q.pop();
        int nw=merge(y,x);
        printf("%d\n",tr[nw].w);
        q.push({-tr[nw].c,nw});
	}
    printf("%d",tr[q.top().second].w);
}