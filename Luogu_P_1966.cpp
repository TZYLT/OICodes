#include<bits/stdc++.h>
using namespace std;
#define p 99999997
template <int C>
struct FenwickTree{
    int c[C+1];
    FenwickTree()=default;
    int ask(int x){
        int ans=0;
        for(;x;x-=x&-x)ans+=c[x];
        return ans;
    }
    void add(int x,int d){
        for(;x<=C;x+=x&-x) c[x]+=d; 
    }
};
FenwickTree<100100> st;
pair<int,int> a[100100],b[100100];
int c[100100];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].first),a[i].second=i;
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i].first),b[i].second=i;
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
        c[a[i].second]=b[i].second;
    int ans=0;
    for(int i=n;i>=1;i--){
        (ans+=st.ask(c[i]-1))%=p;
        //printf("%d ",c[i]);
        st.add(c[i],1);
    }
    printf("%d\n",ans);

}

