#include<bits/stdc++.h>
using namespace std;
int a[101][5],l[101],r[101];
struct pt{int a,b,c,d,t;};
pt f[101][101][3][3];
int k,x,n,m;

void write(pt x,int la,int lb,int lc,int ld){
	vector<pt> q;deque<int> ax;
    while(la>0){
        //printf("[%d,%d,%d,%d]\n",la,lb,lc,ld);
        q.push_back({la,lb,lc,ld,0});
        la=x.a;lb=x.b;lc=x.c;ld=x.d;
		x=f[x.a][x.b][x.c][x.d];
    }
    
    ax.push_back(q[q.size()-1].d);
    for(int i=q.size()-2;i>=0;i--){
        if(q[i].c!=q[i+1].c) ax.push_front(q[i].c);
        else if(q[i].d!=q[i+1].d) ax.push_back(q[i].d);
        else ax.push_back(q[i].d);
    }
	// while(1){
	// 	if(lc!=x.c) ax.push_front(x.c);
	// 	else if(ld!=x.d) ax.push_back(x.d);
	// 	else ax.push_back(x.d);
    //     printf("[%d,%d,%d,%d]->[%d,%d,%d,%d]\n",la,lb,lc,ld,x.a,x.b,x.c,x.d);
	// 	la=x.a;lb=x.b;lc=x.c;ld=x.d;
	// 	x=f[x.a][x.b][x.c][x.d];
	// }
	while(ax.size()){
		if(ax.front()==0)printf("B");
		if(ax.front()==1)printf("A");
		if(ax.front()==2)printf("C");
		ax.pop_front();
	}
	printf("\n");
	
}
int main(){
    scanf("%d%d%d%d",&k,&x,&n,&m);
    a[1][0]=1;
    a[2][1]=1;
    l[1]=0;r[1]=0;
    l[2]=1;r[2]=1;
    //0A 1B
    for(int i=3;i<=k;i++){
        a[i][0]=a[i-1][0]+a[i-2][0];
        a[i][1]=a[i-1][1]+a[i-2][1];

        a[i][2]=a[i-1][2]+a[i-2][2]+((r[i-2]==0&&l[i-1]==1)?1:0);
        a[i][3]=a[i-1][3]+a[i-2][3]+((r[i-2]==1&&l[i-1]==0)?1:0);
        a[i][4]=a[i-1][4]+a[i-2][4]+((r[i-2]==1&&l[i-1]==1)?1:0);
        l[i]=l[i-2];r[i]=r[i-1];
        //printf("%d %d %d %d %d\n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4]);
    }
    
    f[1][0][0][0]={0,0,0,0,1};f[1][0][1][1]={0,0,0,0,1};f[1][0][2][2]={0,0,0,0,1};
    for(int i=1;i<=max(n,m);i++)
        for(int c=0;c<=max(n,m);c++)
            for(int l=0;l<=2;l++)
                for(int r=0;r<=2;r++)
                    for(int s=0;s<=2;s++){
                        //printf("[%d,%d,%d,%d:%d]->[%d,%d,%d,%d]\n",i,c,l,r,f[i][c][l][r].t,i+1,c,s,r);
                        //printf("[%d,%d,%d,%d:%d]->[%d,%d,%d,%d]\n",i,c,l,r,f[i][c][l][r].t,i+1,c,l,s);
                        if(r==1&&s==2){if(f[i+1][c+1][l][s].t==0)f[i+1][c+1][l][s]={i,c,l,r,f[i][c][l][r].t};}
                        else if(f[i+1][c][l][s].t==0)f[i+1][c][l][s]={i,c,l,r,f[i][c][l][r].t};
                        if(s==1&&l==2){if(f[i+1][c+1][s][r].t==0)f[i+1][c+1][s][r]={i,c,l,r,f[i][c][l][r].t};}
                        else if(f[i+1][c][s][r].t==0)f[i+1][c][s][r]={i,c,l,r,f[i][c][l][r].t};
           	        }
    pt ansn,ansm;
    for(int i=0;i<=n;i++)
        for(int nl=0;nl<=2;nl++)
            for(int nr=0;nr<=2;nr++)
    for(int j=0;j<=m;j++)
        for(int ml=0;ml<=2;ml++)
            for(int mr=0;mr<=2;mr++)
                if(f[n][i][nl][nr].t==1&&f[m][j][ml][mr].t==1){
                    //cout<<i<<' '<<j<<endl;
                    if(a[k][0]*i+a[k][1]*j+((nr==1&&ml==2)?a[k][2]:0)+((nl==2&&mr==1)?a[k][3]:0)+((ml==2&&mr==1)?a[k][4]:0)==x){
                        ansn=f[n][i][nl][nr];
                        ansm=f[m][j][ml][mr];
                        write(ansn,n,i,nl,nr);
						write(ansm,m,j,ml,mr);
                        return 0;
                    }
                }
                    
	printf("Happy new year!\n");
}
