#include<bits/stdc++.h>
using namespace std;
int t,l,r;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&l,&r);
        if(l==r){
            printf("-1\n");
        }else if(((r-l+1)%2)==0){
            for(int i=l;i<=r;i+=2)
                printf("%d %d\n",i,i+1),
                printf("%d %d\n",i+1,i);
        }else if((((r-l+1)%2)==1)&&((l%2==0)&&(r%2==0))){
            printf("-1\n");
        }else {
            printf("%d %d\n",l,l+1);
            printf("%d %d\n",l+1,l+2);
            printf("%d %d\n",l+2,l);
            for(int i=l+3;i<=r;i+=2)
                printf("%d %d\n",i,i+1),
                printf("%d %d\n",i+1,i);
        }
    }
}