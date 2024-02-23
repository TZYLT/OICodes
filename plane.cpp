#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
int flyqun[4][9][2]={{{-1,-2},{-1,-1},{-1,0},{-1,1},{-1,2},{-2,0},{-3,-1},{-3,0},{-3,1}},
{{1,-2},{1,-1},{1,0},{1,1},{1,2},{2,0},{3,-1},{3,0},{3,1}},
{{-2,1},{-1,1},{0,1},{1,1},{2,1},{0,2},{-1,3},{0,3},{1,3}},
{{-2,-1},{-1,-1},{0,-1},{1,-1},{2,-1},{0,-2},{-1,-3},{0,-3},{1,-3}}};
//0-Nothing 1-Body 2-Head
char __map[11][11][500000],head[500000][6];
int cnt=0,tot=0;
int rec[11][11][3];
char _map[11][11];
bool v[500000],used[11][11];
vector<pair<int,int> > t;
void init(int s,int x,int y){
		if(s==3){
			cnt++;
			for(int i=1;i<=10;i++)
				for(int j=1;j<=10;j++){
					__map[i][j][cnt]=_map[i][j];
					rec[i][j][_map[i][j]]++;
				}
						
			head[cnt][0]=t[1].first;
			head[cnt][1]=t[1].second;
			head[cnt][2]=t[2].first;
			head[cnt][3]=t[2].second;
			head[cnt][4]=t[3].first;
			head[cnt][5]=t[3].second;
			return;
		}
		for(int i=x;i<=10;i++)
			for(int j=(i==x?y:1);j<=10;j++){
				if(_map[i][j]==1||_map[i][j]==2)continue;
				for(int k=0;k<=3;k++){
					bool flag=1;
					for(int l=0;l<=8;l++)
						if(flyqun[k][l][0]+i>10||flyqun[k][l][0]+i<1||flyqun[k][l][1]+j>10||flyqun[k][l][1]+j<1
							||_map[flyqun[k][l][0]+i][flyqun[k][l][1]+j]==1||_map[flyqun[k][l][0]+i][flyqun[k][l][1]+j]==2)
							{flag=0;break;}
					if(flag==0)continue;
					_map[i][j]=2;
					for(int l=0;l<=8;l++)
						_map[flyqun[k][l][0]+i][flyqun[k][l][1]+j]=1;
					t.push_back(make_pair(i,j));
					init(s+1,1,1);
					t.pop_back();
					_map[i][j]=0;
					for(int l=0;l<=8;l++)
						_map[flyqun[k][l][0]+i][flyqun[k][l][1]+j]=0;	
			}
	}
}
void chan(int x,int y,int k){
	tot=0;
	for(int i=1;i<=cnt;i++)
		if(v[i]==0&&__map[x][y][i]==k) tot++;
	else v[i]=1;
}

void change_remake(int x,int y,int k){
	tot=0;
	for(int i=1;i<=cnt;i++){
		if(v[i]==0&&__map[x][y][i]==k) tot++;
		else if(v[i]==0){
			v[i]=1;
			for(int j=1;j<=10;j++)
				for(int l=1;l<=10;l++)
					rec[j][l][__map[j][l][i]]--;	
		}
		else v[i]=1;
	}
}
int chance[11][11];
void find(void){
	for(int i=1;i<=cnt;i++)
		if(v[i]==0){
			chance[head[i][0]][head[i][1]]++;
			chance[head[i][2]][head[i][3]]++;
			chance[head[i][4]][head[i][5]]++;
		}
}
int topans,step;double st;
int checker(int x,int y){
	//printf("%d %d\n",x,y);
	step++;
	if(x==0&&y==0){
		if(step==3)printf("100 %d %.4lf\n",step,clock()-st);
		if(step<=10&&step>=4)printf("9 %d %.4lf\n",step,clock()-st);
		if(step<=15&&step>=11)printf("6 %d %.4lf\n",step,clock()-st);
		if(step<=20&&step>=16)printf("5 %d %.4lf\n",step,clock()-st);
		if(step<=25&&step>=21)printf("3 %d %.4lf\n",step,clock()-st);
		if(step<=35&&step>=26)printf("2 %d %.4lf\n",step,clock()-st);
		fflush(stdout);
		return -1;
	} 
	return __map[x][y][topans];
	
}
int main(){
	freopen("step.out","w",stdout);
	srand(time(0)+(int)100*clock());
	st=clock();
	init(0,1,1);
	tot=cnt;
	
	topans=rand()%(cnt+1);
	step=-1;
	
	int hitted=0;
	while(1){
		if(tot>=48){
			//printRec();
			double change[11][11];
			for(int i=1;i<=10;i++){
				for(int j=1;j<=10;j++){
					change[i][j]=0.0;
					if(!used[i][j])
						for(int k=0;k<=2;k++){
							int chance_tot=rec[i][j][k];
							change[i][j]+=(chance_tot==0)?0.0:((double)(log2(tot)-log2(chance_tot))*((double)chance_tot/(tot)));	
						}
				}
			}
				
			double maxx=-1.0;int nx,ny;
			vector<pair<int,int> > ans;
			
			for(int i=10;i>=1;i--)
				for(int j=10;j>=1;j--)
					if(used[i][j]==0)maxx=max(maxx,change[i][j]);
			for(int i=10;i>=1;i--)
				for(int j=10;j>=1;j--)
					if(used[i][j]==0&&maxx-change[i][j]<EPS) ans.push_back(make_pair(i,j));
			
			int temp=rand()%ans.size();
			nx=ans[temp].first;
			ny=ans[temp].second;	
			used[nx][ny]=1;
			
			int in=checker(nx,ny);
			
			if(in==2)hitted++;
			if(hitted==3)in=checker(0,0);
			if(in==-1)return 0;
			change_remake(nx,ny,in);
		}else{
			memset(chance,0,sizeof(chance));
			find();
			int maxx=-1;int nx=0,ny=0;
			for(int i=1;i<=10;i++)
				for(int j=1;j<=10;j++)
					if(maxx<chance[i][j]&&used[i][j]==0){
						maxx=chance[i][j];
						nx=i;
						ny=j;
					}
			used[nx][ny]=1;
			int in=checker(nx,ny);
			
			if(in==2)hitted++;
			if(hitted==3)in=checker(0,0);
			if(in==-1)return 0;
			chan(nx,ny,in);
		}	
	}
}
