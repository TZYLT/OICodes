#include<bits/stdc++.h>
using namespace std;
#define M 4000500
int n,nxt[M];
string s;
void kmp(string &s){
	nxt[1]=0;
	for(int i=2;i<=s.size()-1;i++){
		int p=nxt[i-1];
		while(p!=0){
			if(s[p+1]==s[i])break;
			else p=nxt[p];
		}
		nxt[i]=(s[p+1]==s[i])?p+1:0;
	}
}
int head[M],nextt[M],ver[M],cnt;
int size[M],dep[M],hson[M],fa[M],top[M];
void add(int x,int y){
	cnt++;
	ver[cnt]=y;
	nextt[cnt]=head[x];
	head[x]=cnt;
}

void dfsI(int x,int ffa){
	int s=-1;
	size[x]=1;fa[x]=ffa;
	dep[x]=dep[ffa]+1;
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=ffa){
			dfsI(ver[i],x);
			size[x]+=size[ver[i]];
			if(s<size[ver[i]])s=size[ver[i]],hson[x]=ver[i];
		}		
}

void dfsII(int x,int tp){
	//printf("[%d]",x);
	top[x]=tp;
	if(!hson[x])return;
	dfsII(hson[x],tp);
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=fa[x]&&ver[i]!=hson[x])
			dfsII(ver[i],ver[i]);
}

int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

int main(){
	cin>>s;
	s=' '+s;
	kmp(s);
	for(int i=1;i<=s.size()-1;i++)
		add(i+1,nxt[i]+1),add(nxt[i]+1,i+1);
	dfsI(1,0);
	dfsII(1,1);
	scanf("%d",&n);
	while(n--){
		int x,y;
		scanf("%d%d",&x,&y);
		x++;y++;
		int l=lca(x,y);
		printf("%d\n",l==x||l==y?fa[l]-1:l-1);
	}
}
