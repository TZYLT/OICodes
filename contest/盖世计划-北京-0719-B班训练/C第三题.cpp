#include<bits/stdc++.h>
using namespace std;
#define M 301000
int head[M],nextt[M],tag[M],ver[M],cnt;
int n;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
struct node{
	int son[26];
	bool tag;
}trie[100100];
int tot;
void insert(string &s){
	int now=0;
	for(int i=0;i<s.size();i++){
		if(trie[now].son[s[i]-'a'])now=trie[now].son[s[i]-'a'];
		else {
			trie[now].son[s[i]-'a']=++tot;
			now=tot;
		}
	}
	trie[now].tag=1;
}
int sumv;
void dfs(int x){
	
	if(trie[x].tag)tag[x+1]=1;
	for(int i=0;i<26;i++)
		if(trie[x].son[i]){
			//printf("[%d->%d]:%c\n",x+1,trie[x].son[i]+1,'a'+i);
			add(x+1,trie[x].son[i]+1);
			add(trie[x].son[i]+1,x+1);
			dfs(trie[x].son[i]);
		}
			
}
int dep[M],ans;
priority_queue<int> q[M];
void sol(int x,int fa){
	//printf("[%d]:%d\n",x,ans);
	dep[x]=dep[fa]+1;
	if(tag[x]) q[x].push(dep[x]),ans+=dep[x];
	for(int i=head[x];i;i=nextt[i])
		if(ver[i]!=fa){
			sol(ver[i],x);
			if(q[x].size()<q[ver[i]].size())swap(q[x],q[ver[i]]);
			while(q[ver[i]].size())
				q[x].push(q[ver[i]].top()),q[ver[i]].pop();
		}
	
	if(tag[x]==0&&q[x].size()>0){
		int t=q[x].top();q[x].pop();
		ans-=(t-dep[x]);
		q[x].push(dep[x]);
	}
	
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		insert(s);
	}
	dfs(0);
	for(int i=head[1];i;i=nextt[i])
		sol(ver[i],1);
	printf("%d\n",ans);
}
