#include<bits/stdc++.h>
using namespace std;
#define M 100100000
bool v[M];
int p[M],k;
void ls(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i;
        for(int j=1;i*p[j]<=n&&j<=k;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
int n,q;
int main(){
    scanf("%d%d",&n,&q);
    ls(n);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",p[x]);
    }
}