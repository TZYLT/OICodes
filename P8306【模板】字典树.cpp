#include<bits/stdc++.h>
using namespace std;
int n,m,tot,tag[3000010];
map<char,int> mp;
int trie[3000010][63];
void insert(char *s) {
	int len=strlen(s+1),p=0;
	for(int i=1; i<=len; i++) {
		if(!trie[p][mp[s[i]]]) trie[p][mp[s[i]]]=++tot;
		p=trie[p][mp[s[i]]];
		tag[p]++;
	}
}
int query(char *s) {
	int len=strlen(s+1),p=0;
	for(int i=1; i<=len; i++) {
		if(!trie[p][mp[s[i]]]) return 0;
		p=trie[p][mp[s[i]]];
	}
	return tag[p];
}
char s[(int)(3e6+10)];
signed main() {
	int t,id=0;
	cin>>t;
	for(char i='a'; i<='z'; i++) mp[i]=++id;
	for(char i='A'; i<='Z'; i++) mp[i]=++id;
	for(char i='0'; i<='9'; i++) mp[i]=++id;
	while(t--) {
		cin>>n>>m;
		for(int i=0; i<=tot; i++) {
			tag[i]=0;
			for(int j=0; j<=62; j++) {
				trie[i][j]=0;
			}
		}
		tot=0;
		for(int i=1; i<=n; i++) {
			cin>>(s+1);
			insert(s);
		}
		for(int i=1; i<=m; i++) {
			cin>>(s+1);
			cout<<query(s)<<"\n";
		}
	}
	system("pause > null");
}
