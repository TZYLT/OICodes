#include<bits/stdc++.h>
using namespace std;
int a[10100];
int n,k;
vector<pair<int,int> > ans;
bool check(int x,bool tag){
    //printf("[%d]",x);//fflush(stdout);
    int sum=1,t=0,ls=n;
    for(int i=n;i>=1;i--){
        if(t+a[i]>x){
            sum++,t=0;
            if(tag)ans.push_back({i+1,ls});
            ls=i;
        }
        t+=a[i];
    }
    if(tag)ans.push_back({1,ls});
    return sum<=k;
}
void search(int l,int r){
    if(l==r)return check(l,1),void();
    int mid=(l+r)>>1;
    if(check(mid,0))return search(l,mid);
    else return search(mid+1,r);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    search(1,10000000);
    for(int i=k;i>=1;i--)
        if(i<=ans.size())printf("%d %d\n",ans[i-1].first,ans[i-1].second);
}