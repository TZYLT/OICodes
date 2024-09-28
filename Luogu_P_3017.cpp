#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int w[505][505];
int s[505][505];
bool checkl(int l,int r,int x){
    //if(s[r][m]-s[l-1][m]<b*x)return 0;
    int sum=0;
    for(int i=1,la=1;i<=m;i++){
        if(s[r][i]+s[l-1][la-1]-s[r][la-1]-s[l-1][i]>=x)
            sum++,la=i+1;
    }
    if(sum>=b)return 1;
    else return 0;
}
bool check(int x){
    int sum=0;
    for(int i=1,l=1;i<=n;i++){
        if(checkl(l,i,x))sum++,l=i+1;
    }
    if(sum>=a)return 1;
    return 0;
}
int search(int l,int r){
    if(l+1==r){
        if(check(r))return r;
        else return l;
    }

    if(l==r)return l;
    int mid=(l+r)>>1;
    if(!check(mid))return search(l,mid-1);
    else return search(mid,r);
}
int main(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&w[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)  
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+w[i][j];

    printf("%d\n",search(0,10000000));
}
