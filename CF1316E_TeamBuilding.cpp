#include<bits/stdc++.h>
using namespace std;
long long f[100100][1<<7];
int n,p,k;
int a[100100],b[100100][8];
vector<pair<int,int> > st;
int main(){
    scanf("%d%d%d",&n,&p,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),st.push_back(make_pair(a[i],i));
    sort(st.begin(),st.end());
    reverse(st.begin(),st.end());
    for(int i=1;i<=n;i++)
        for(int j=1;j<=p;j++)
            scanf("%d",&b[i][j]);
    
    for(int i=0;i<n;i++)
        for(int s=0;s<(1<<p);s++)
            if(i>=__builtin_popcount(s)){
                if(i-__builtin_popcount(s)<k)
                    f[i+1][s]=max(f[i+1][s],f[i][s]+st[i].first);
                else f[i+1][s]=max(f[i+1][s],f[i][s]);
                for(int j=0;j<p;j++)
                    if(((s>>j)&1)==0)
                        f[i+1][s|(1<<j)]=max(f[i+1][s|(1<<j)],f[i][s]+b[st[i].second][j+1]);
            }
    printf("%lld\n",f[n][(1<<p)-1]);
}