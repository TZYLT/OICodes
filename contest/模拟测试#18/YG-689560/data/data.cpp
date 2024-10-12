#include<bits/stdc++.h>
using namespace std;
#define p 998244353
#define inv2 499122177
int n,m;
int v[5050],l[5050],r[5050];
int st[20002000];
inline void ck(int &x){x=(x>=p)?x-p:x;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",v+i,l+i,r+i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j){
                int t=1ll*v[i]*v[j]%p;
                ck(st[l[i]+l[j]]+=t);
                ck(st[r[i]+r[j]+2]+=t);
                ck(st[l[i]+r[j]+1]+=p-t);
                ck(st[l[j]+r[i]+1]+=p-t);
            }
    for(int i=1;i<=20000000;i++)
        ck(st[i]+=st[i-1]);
    for(int i=1;i<=20000000;i++)
        ck(st[i]+=st[i-1]);
    while(m--){
        int k;
        scanf("%d",&k);
        printf("%lld\n",1ll*st[k]*inv2%p);
    }
}