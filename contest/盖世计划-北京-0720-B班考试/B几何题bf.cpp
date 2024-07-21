#include<bits/stdc++.h>
using namespace std;
#define M 3030
int n,q;
long long a[M];
int main(){
    freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    while(q--){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==0)a[l]=r;
        else {
            long long ans=0;
            for(int i=r;i>=l;i--)
                for(int j=i-1;j>=l;j--) 
                    for(int k=j-1;k>=l;k--)
                        if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[k]+a[j]>a[i]) 
                            ans=max(ans,a[i]+a[j]+a[k]);
            printf("%lld\n",ans);        
        }
    }
    
}