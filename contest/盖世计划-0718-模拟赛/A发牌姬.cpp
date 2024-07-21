// #include<bits/stdc++.h>
// using namespace std;
// #define M 200200
// int n,m,B;
// pair<int,int> s[200200];

// int head[M],nextt[M],id[M],v[M],ver[M],cnt=1,tot[M];
// void add(int x,int y,int z){
// 	++cnt;
// 	tot[x]++;
// 	ver[cnt]=y;
// 	nextt[cnt]=head[x];
// 	id[cnt]=z;
// 	head[x]=cnt;
// }
// vector<int> ans;
// void dfs(int x){
// 	for(int i=head[x];i;i=nextt[i])
// 		if(v[i]==0){
// 			v[i]=1;
// 			ans.push_back(id[i]);
// 			dfs(ver[i]);
// 		}
// }

// int main(){
//     freopen("card1.in","r",stdin);
//     freopen("card.out","w",stdout);
//     double st=clock();
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>n>>m>>B;
//     for(int i=1;i<=n;i++){
//     	string in;
// 		cin>>in;
// 		vector<int> t;
// 		for(int j=0;j<in.size();j++)
// 			if(in[j]=='1')t.push_back(j);
// 		if(t.size()>=2)
// 			for(int j=0;j<t.size()-1;j++)
// 				if((t[j+1]-t[j])%m!=0){
// 					cout<<"-1"<<endl;
// 					return 0;
// 				}
// 		s[i].first=t[0];
// 		for(int j=in.size()-1;j>=0;j--)
// 			if(in[j]=='1'){
// 				s[i].second=in.size()-1-j;
// 				break;
// 			}
// 	}
// 	for(int i=n;i>=1;i--)
// 		add(s[i].first,s[i].second,i);

// 	dfs(B);
// 	if(ans.size())
// 		for(auto c:ans) 
// 			cout<<c<<' ';
// 	else cout<<"-1"<<endl;
// 	clog<<clock()-st;
// }
#include<bits/stdc++.h>
using namespace std;
int n,m,B;
pair<int,int> s[200200];
set<pair<int,int> > ver[200200];
bool v[200200];
vector<int> ans;
long long sum;
void dfs(int b){
	pair<int,int> c;
	for(auto it=ver[b].begin();it!=ver[b].end();it=ver[b].upper_bound(c)){
		sum++;
		c=*it;
		ver[b].erase(c);
		ans.push_back(c.second);
		dfs(m-s[c.second].second-1);
		
	}
		
}
int main(){
    freopen("card4.in","r",stdin);
    freopen("card.out","w",stdout);
    //st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>B;
    for(int i=1;i<=n;i++){
    	string in;
		cin>>in;
		vector<int> t;
		for(int j=0;j<in.size();j++)
			if(in[j]=='1')t.push_back(j);
		if(t.size()>=2)
			for(int j=0;j<t.size()-1;j++)
				if((t[j+1]-t[j])%m!=0){
					cout<<"-1"<<endl;
					return 0;
				}
		s[i].first=t[0];
		for(int j=in.size()-1;j>=0;j--)
			if(in[j]=='1'){
				s[i].second=in.size()-1-j;
				break;
			}
		ver[s[i].first].insert(make_pair(s[i].second,i));
		//cout<<s[i].first<<' '<<s[i].second<<endl;
	}
	//sort(s+1,s+1+n);
	dfs(B);
	//clog<<sum<<' ';
	if(ans.size()==n)
		for(auto c:ans)cout<<c<<' ';
	else cout<<"-1"<<endl;
}
