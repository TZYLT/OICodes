#include<bits/stdc++.h>
using namespace std;
int a[100100],n,T;
bool check(int k){
    priority_queue<int> q;
    int ans=0;
    for(int i=1;i<=min(k,n);i++)
        q.push(-a[i]);
    for(int i=k+1;i<=n;i++){
        int t=-q.top();q.pop();
        ans=max(ans,t);
        q.push(-t-a[i]);
    }
    while(q.size()){
        int t=-q.top();q.pop();
        ans=max(ans,t);
    }
    return ans<=T;
}
int sc(int l,int r){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(check(mid))return sc(l,mid);
    else return sc(mid+1,r);
}
int main(){
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    printf("%d",sc(1,n));
}