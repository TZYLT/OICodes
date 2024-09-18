#include<bits/stdc++.h>
using namespace std;
//up-1 down-2 left-3 right-4
struct st{
	int map[3][3],x,y;
	int mov(int op){
		if(op==1){
			if(y==3)return 1;
			swap(map[x][y],map[x][y+1]);
		}
		if(op==2){
			if(y==1)return 1;
			swap(map[x][y],map[x][y-1]);
		}
		if(op==3){
			if(x==1)return 1;
			swap(map[x][y],map[x-1][y]);
		}
		if(op==4){
			if(x==3)return 1;
			swap(map[x][y],map[x+1][y]);
		}
	}
};
map<st,int> find;

int cnt;
st start,en;
int main(){
	en.y=2;
	en.x=2;
	en.map[0][0]=1;en.map[0][1]=2;en.map[0][2]=3;
	en.map[1][0]=8;en.map[1][1]=0;en.map[1][2]=4;
	en.map[2][0]=7;en.map[2][1]=6;en.map[2][2]=5;
	
	for(int i=1;i<=9;i++){
		char c;
		scanf("%c",&c);
		start.map[(int)(i/3)][i%3]=c-'0';
	}
}
