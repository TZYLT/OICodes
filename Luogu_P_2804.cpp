#include<bits/stdc++.h>
using namespace std;
int sum[200200],temp[200200];
int n,m;
long long ans;
int merge(int l,int mid,int r){
    int p1=l,p2=mid+1,k=l-1;
    while(p1<=mid&&p2<=r){
        if(sum[p1]<sum[p2]){
            ans+=(mid-p1+1);
            ans%=92084931;
            temp[++k]=sum[p2];
            p2++;
        }
        else if(sum[p1]>=sum[p2]){
            temp[++k]=sum[p1];
            p1++;
        }
    }
    while(p1<=mid) temp[++k]=sum[p1++];
    while(p2<=r) temp[++k]=sum[p2++];
    for(int i=l;i<=r;i++)
        sum[i]=temp[i];
}
void mergesort(int l,int r){
    if(l<r){
        int mid=(l+r)>>1;
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,r);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",sum+i),sum[i]-=m;
    for(int i=1;i<=n;i++)
        sum[i]+=sum[i-1];
    mergesort(0,n);
    printf("%d",ans);
}   