#include<bits/stdc++.h>
using namespace std ;
const int N=4e7+10;
const int M=1e5+10;
const int mod=(1<<30);
int n,type,x,y,z,m;
int a[N],b[N],p[M],l[M],r[M],q[N],pre[N];
long long sum[N];
long long d(int x){return sum[x]-sum[pre[x]];}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>type;
    if(type){
        cin>>x>>y>>z>>b[1]>>b[2]>>m;
        for(int i=1;i<=m;i++)
            cin>>p[i]>>l[i]>>r[i];
        for(int i=3;i<=n;i++)
            b[i]=(0ll+1ll*b[i-1]*x+1ll*b[i-2]*y+z)%mod;
        for(int i=1;i<=m;i++)
            for(int j=p[i-1]+1;j<=p[i];j++){
                a[j]=(b[j]%(r[i]-l[i]+1))+l[i];
                sum[j]=sum[j-1]+a[j];
            }
	}
    else
  	    for(int i=1;i<=n;i++)
            cin>>a[i],sum[i]=sum[i-1]+a[i];
	int h,t;
    q[h=t=0]=0;
    for(int i=1;i<=n;i++) {
        while(h<t&&d(q[h+1])+sum[q[h+1]]<=sum[i])++h;
            pre[i]=q[h];
        while(h<t&&d(q[t])+sum[q[t]]>=d(i)+sum[i])--t;
        q[++t]=i;
    }
    int now=n;
    __int128 ans=0,tmp=1;
	while(now){
        tmp=d(now);
        tmp*=d(now);
        ans+=tmp;
        now=pre[now];
    }
	int st[50],tp=0;
	while(ans){
        st[++tp]=ans%10;
        ans/=10;
    }
	while(tp)
        cout<<st[tp--];
  return 0;
}