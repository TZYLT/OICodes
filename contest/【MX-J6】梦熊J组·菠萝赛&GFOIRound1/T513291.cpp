#include<bits/stdc++.h>
using namespace std;
int t,a[1001000];
int main(){
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(m*2-1>=n){
            for(int j=1;j<=n;j++)
                a[j]=j;
                swap(a[n],a[m]);
        }
        else
        for(int i=min(m,n);i>=1;i--)
            if(n%i==0){
                for(int j=1;j<=n;j++)
                    a[j]=j;
                for(int j=1;i*j<=n;j++)
                    reverse(a+i*j-i+1,a+i*j+1);
                break;
            }
        for(int j=1;j<=n;j++)
            printf("%d ",a[j]);
        printf("\n");
        //for(int i=sqrt(n);i>=1;i--)

            

    }
}