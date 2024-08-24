#include<bits/stdc++.h>
using namespace std;
long long t,l,r;
long long sol(long long l,long long r,int len){
    
    if(len==1)return l==r?1:2;
    long long ll=(l|((1ll<<(len/2))-1ll)),ans=0;
    if(ll>=r){
        ans=sol(l&((1ll<<(len/2))-1ll),r&((1ll<<(len/2))-1ll),len/2);
        printf("A[%lld,%lld,%d]:%lld\n",l,r,len,ans);
        return ans;
    }
    else ans+=sol(l&((1ll<<(len/2))-1ll),ll&((1ll<<(len/2))-1ll),len/2);
    if(((r>>(len/2))-(l>>(len/2)))>2)
        ans+=((r>>(len/2))-(l>>(len/2))-2)*sol(0,(1ll<<(len/2))-1ll,len/2);
    printf("B[%lld,%lld,%d]:%lld\n",l,r,len,ans);
    ans+=sol(0,r&((1ll<<(len/2))-1ll),len/2);
    printf("C[%lld,%lld,%d]:%lld\n",l,r,len,ans);
    return ans;
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",sol(l,r,64));
    }
}