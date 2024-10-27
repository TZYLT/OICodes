#include<bits/stdc++.h>
using namespace std;
struct middum{
    priority_queue<int> maxx,minn;
    int mid;
    void insert(int x,int y){
        if(x<mid&&y<mid){
            minn.push(x);minn.push(y);
            maxx.push(-mid);
            mid=minn.top();minn.pop();
        }else if(x<mid&&y>mid){
            minn.push(x);
            maxx.push(-y);
        }else if(x>mid&&y<mid){
            minn.push(y);
            maxx.push(-x);
        }else{
            maxx.push(-x);maxx.push(-y);
            minn.push(mid);
            mid=-maxx.top();maxx.pop();
        }
    }
    void init(int x){
        mid=x;
    }
}st[10010];
int a[10010],n;
long long ans=0;
int main(){
    freopen("book.in","r",stdin);
    freopen("book.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int l=1;l<=n;l++){
        st[l].init(a[l]);
        ans+=1ll*l*l*a[l];
        for(int r=l+2;r<=n;r+=2){
            st[l].insert(a[r],a[r-1]);
            ans+=1ll*l*r*st[l].mid;
        }
    }
    printf("%lld\n",ans);
}