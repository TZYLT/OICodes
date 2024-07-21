#include<bits/stdc++.h>
using namespace std;
#define M 300100
set<int> unmerge;
set<pair<int,int> > edge;
int degree[M],tag[M];
int n,m,k;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        degree[i]=n-1;
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        edge.emplace(make_pair(x,y));
        edge.emplace(make_pair(y,x));
        degree[x]--;degree[y]--;
    }
    
    for(int i=1;i<=n;i++)
        if(degree[i]==0){
            printf("impossible\n");
            return 0;
        }
    if(degree[1]<k){
        printf("impossible\n");
        return 0;
    }
    int sum=0;
    for(int i=2;i<=n;i++) unmerge.emplace(i);
    for(int i=2;i<=n;i++)
        if(unmerge.count(i)>0){
            sum++;
            queue<int> q;
            q.push(i);unmerge.erase(i);
            while(q.size()){
				int x=q.front();q.pop();
				if(edge.count(make_pair(1,x))==0) tag[sum]=1;
				//unmerge.erase(x);
				vector<int> del;
				for(auto c:unmerge)
					if(edge.count(make_pair(x,c))==0)
						q.push(c),del.push_back(c);
					else edge.erase(make_pair(x,c));
				for(auto c:del) unmerge.erase(c);
			}
        }
        
    for(int i=1;i<=sum;i++)
    	if(!tag[i]){
		    printf("impossible\n");
		    return 0;
		}
	if(sum>k){
		printf("impossible\n");
		return 0;
	}
	printf("possible\n");
	return 0;
}

