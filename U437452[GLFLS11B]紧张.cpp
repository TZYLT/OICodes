#include<bits/stdc++.h>
using namespace std;
int n,m;
int l[300300],r[300300],s[300300];
int il[300300],ir[300300];
int c[600300];
#define p 998244353
int ask(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=c[x];
    return ans;
}
void add(int x,int d){
    for(;x<=600000;x+=x&-x) c[x]+=d; 
}

vector<int> sorted;
map<int,int> mmap;
long long ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&l[i],&r[i],&s[i]);
        r[i]++;
        sorted.push_back(l[i]);
        sorted.push_back(r[i]);
    }
    sort(sorted.begin(),sorted.end());
    int len=unique(sorted.begin(),sorted.end())-sorted.begin();
    
    for(int i=0;i<len;i++)
        mmap[sorted[i]]=i+2;
    for(int i=1;i<=m;i++)
        il[i]=mmap[l[i]];
    
    for(int i=1;i<=m;i++)
        ir[i]=mmap[r[i]];
    for(int i=1;i<=m;i++)
        add(ir[i],s[i]),add(il[i]-1,-s[i]);
    
    for(int i=2;i<len+2;i++){
        long long t=ask(i)-ask(i-1);
        ans=(ans+1ll*t*t%p*(sorted[i-1]-sorted[i-2])%p)%p;
        printf("[%d,%d]%d\n",sorted[i-3],sorted[i-2]-1,t);
    }
    printf("%lld\n",ans);
}