#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    b[m+1]=(1<<30);
    int last=1,l,t=0;
    for(int i=1;i<=n;i++){
        while(1){
            l=upper_bound(b+1,b+m+1,t)-b;
            last=b[l];
            //printf("[%d]:L:%d,%d S:%d\n",t,l,last,a[i]);
            
            if(a[i]+t<last){
                t=a[i]+t;
                break;
            }else t=last;
        }
    }    
    printf("%d\n",t);
}
