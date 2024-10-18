#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p,q;
double r;
int t[100100];
int ans,ts=0,rs=0,id;
signed main(){
    freopen("t1_4.in","r",stdin);
    scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",t+i);
    while(1){
        if(id>=n)break;
        ts++;
        int nr=ceil((long double)p*m*ts/q)-rs;
        if(nr<=0)nr=0;
        nr=m-nr;
        int iid=id+1,sum=0;
        while(1){
            if(sum+t[iid]>nr)break;
            sum+=t[iid];iid++;
        }
        id=iid-1;rs+=m-sum;
    }
    printf("%lld\n",ts);
}