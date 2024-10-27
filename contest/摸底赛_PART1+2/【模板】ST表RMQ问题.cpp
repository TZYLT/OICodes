#include<bits/stdc++.h>
using namespace std;
int st[30][400200];
int n,m;
void init(void){
    int lim=__lg(n)+1;
    for(int i=1;i<=lim;i++)
        for(int j=1;j<=n;j++)
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int ask(int l,int r){
    int lim=__lg(r-l+1);
    return max(st[lim][l],st[lim][r-(1<<lim)+1]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&st[0][i]);
    init();
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",ask(l,r));
    }
}