#include<bits/stdc++.h>

template <int MV,int ME>
class Map{
	public:
		int ver[MV],edge[ME],next[ME];
		int head[MV],tot;
		
		void add(int x,int y,int z);
};

template <int MV,int ME>
void Map<MV,ME>::add(int x,int y,int z){
	ver[++tot]=y,edge[tot]=z;
	next[tot]=head[x],head[x]=tot;
}

/*
	for(int i=head[i];i;i=next[i])
		int y=ver[i],z=edge[i];
*/

