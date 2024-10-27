#include<bits/stdc++.h>
using namespace std;
int minl,minr,l,r;
int op,x,y,n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&op,&x,&y);
        if(x==1&&y==1){
            l-=op;
            minl=min(minl,l);
            l+=op;
        }else if(x==2&&y==2){
            r-=op;
            minr=min(minr,r);
            r+=op;
        }else if(x==1&&y==2){
            l-=op;
            minl=min(minl,l);
            r+=op;
        }else if(x==2&&y==1){
            r-=op;
            minr=min(minr,r);
            l+=op;
        }
    }
    printf("%d %d\n",-minl,-minr);
}   