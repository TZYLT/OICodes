#include<bits/stdc++.h>
using namespace std;
#define M 660
int a[M][M],n,p;
int GE(void){
    int ans=1,w=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;++j){
            while(a[i][i]){
                int d=a[j][i]/a[i][i];
                for(int k=i;k<=n;++k)
                    a[j][k]=(a[j][k]-1ll*d*a[i][k]%p+p)%p;
                swap(a[i],a[j]);w=-w;
            }
            swap(a[i],a[j]);w=-w;
        }
    }
    for(int i=1;i<=n;i++)ans=1ll*a[i][i]*ans%p;
    ans=1ll*w*ans;
    return (ans+p)%p;
}

int main(){
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;++j)
            scanf("%d",&a[i][j]);
    
    printf("%d\n",GE());

}