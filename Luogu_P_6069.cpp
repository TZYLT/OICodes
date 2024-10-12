#include<bits/stdc++.h>
using namespace std;
int a[200100],n;
long long mm;
__int128 s[200200],sq[200200],sum,m;
bool check(int x){
    for(int l=1,r=x;r<=n;l++,r++){
        __int128 ssq=x*(sq[r]-sq[l-1]);
        __int128 ss=s[r]-s[l-1];ss*=ss;
        if(ssq-ss<=m*x)
            return 1;
    }
    return 0;
}
int search(int l,int r){
    //printf("[%d,%d]",l,r);
    if(l==r)return l;
    int mid=l+((r-l+1)>>1);
    if(check(mid))return search(mid,r);
    else return search(l,mid-1);
}
int main(){
    scanf("%d%lld",&n,&mm);
    m=mm;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),sum+=a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i],sq[i]=sq[i-1]+1ll*a[i]*a[i];
    printf("%d\n",n-search(1,n));
}