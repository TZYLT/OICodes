#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> > q;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,cnt=0;
        scanf("%d%d",&n,&m);
        int _map[n+5][m+5]={0},v[n+5][m+5]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c=getchar();
                while(!isalnum(c))c=getchar();
                if(c=='W')_map[i][j]=1,cnt++;
                else _map[i][j]=0;
            }
        }
        if(!_map[1][1]||!_map[n][m]){
		    printf("J\n");
		    continue;
	    }
        
        int f=0;
        if(_map[1][1]==1)q.push(make_pair(1,1)),v[1][1]=1;
        while(q.size()){
            int x=q.front().first,y=q.front().second;
            if(x==n&&y==m){f=1;break;}
            q.pop();
            if(y+1<=m)if(_map[x][y+1]&&!v[x][y+1])q.push(make_pair(x,y+1)),v[x][y+1]=1;
            if(y-1>=1)if(_map[x][y-1]&&!v[x][y-1])q.push(make_pair(x,y-1)),v[x][y-1]=1;
            if(x+1<=n)if(_map[x+1][y]&&!v[x+1][y])q.push(make_pair(x+1,y)),v[x+1][y]=1;
            if(x-1>=1)if(_map[x-1][y]&&!v[x-1][y])q.push(make_pair(x-1,y)),v[x-1][y]=1;
        }  
        while(q.size())q.pop();
        if(f==0){
            printf("J\n");
            continue;
        }
        printf(((cnt-n-m)&1)?"J\n":"I\n"); 
    }
}