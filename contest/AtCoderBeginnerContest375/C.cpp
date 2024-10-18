#include<bits/stdc++.h>
using namespace std;
char c[3030][3030];
int n;
char ans[3030][3030];
void turn(int x){
    char tp[4][3030]={0};
    for(int i=x;i<=n-x+1;i++)
        tp[0][i]=c[x][i];
    for(int i=x;i<=n-x+1;i++)
        tp[1][i]=c[i][n-x+1];
    for(int i=x;i<=n-x+1;i++)
        tp[2][i]=c[n-x+1][i];
    for(int i=x;i<=n-x+1;i++)
        tp[3][i]=c[i][x];

    for(int i=x;i<=n-x+1;i++)
        c[x][i]=tp[3][n-i+1];
    for(int i=x;i<=n-x+1;i++)
        c[i][n-x+1]=tp[0][i];
    for(int i=x;i<=n-x+1;i++)
        c[n-x+1][i]=tp[1][n-i+1]; 
    for(int i=x;i<=n-x+1;i++)
        c[i][x]=tp[2][i];    
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            c[i][j]=getchar();
            while(c[i][j]!='.'&&c[i][j]!='#')c[i][j]=getchar();
        }
    for(int i=1;i<=n/2;i++){
        if(i%4==1){
            turn(i);
        }
        if(i%4==2){
            turn(i);turn(i);
        }
        if(i%4==3){
            turn(i);turn(i);turn(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%c",c[i][j]);
            printf("\n");
        }
}