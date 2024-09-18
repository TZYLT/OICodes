#include<bits/stdc++.h>
using namespace std;
int n,a[500500],s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),s^=a[i];
    if(s==0){
        printf("lose\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if((s^a[i])<=a[i]){
            printf("%d %d\n",a[i]-(s^a[i]),i);
            a[i]=(s^a[i]);
            for(int i=1;i<=n;i++)
                printf("%d ",a[i]);
            return 0;
        }
    }
}