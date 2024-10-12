#include<bits/stdc++.h>
using namespace std;
template <int C>
struct FenwickTree{
    int c[C+1];
    FenwickTree()=default;
    int ask(int x){
        int ans=0;
        for(;x;x-=x&-x)ans=max(ans,c[x]);
        return ans;
    }
    void add(int x,int d){
        for(;x<=C;x+=x&-x) c[x]=max(c[x],d); 
    }
}; 
FenwickTree<100100> st;
int a[100100],b[100100],p[100100];
int dp[100100];
int n,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),p[a[i]]=i;
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]),b[i]=p[b[i]];
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]=(st.ask(b[i]-1)+1));
        st.add(b[i],dp[i]);
    }
    printf("%d",ans);
}