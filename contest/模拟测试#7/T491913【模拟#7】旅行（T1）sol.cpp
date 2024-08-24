#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long f[505][505];
int a[505];
long long inf=(1ll<<60);
void updata(int k){
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        f[i][j]=min(f[i][j],f[i][k]+f[k][j]); 
}
vector<pair<int,int> > t;
pair<int,int> qs[100100];
long long ans[100100];
vector<int> ask[1000100],st;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
            f[i][j]=inf;
    for(int j=1;j<=100000;j++)
        ans[j]=(1ll<<60);

    for(int i=1;i<=n;i++)
        scanf("%d",a+i),f[i][i]=0;

    for(int i=1;i<=n;i++)
        t.push_back(make_pair(a[i],i));
    sort(t.begin(),t.end());

    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        f[x][y]=z;
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qs[i].first,&qs[i].second);
        ask[max(a[qs[i].first],a[qs[i].second])].push_back(i);
    }
    for(int i=0;i<n;i++){
        updata(t[i].second);
        for(int c:ask[t[i].first])
            st.push_back(c);

        for(int c:st){
            if((__int128)f[qs[c].first][qs[c].second]*t[i].first<=(1ll<<60))
                ans[c]=min(ans[c],1ll*t[i].first*f[qs[c].first][qs[c].second]);
            //cerr<<f[qs[c].first][qs[c].second]*t[i].first;
        }
    }
    for(int i=1;i<=q;i++)
        printf("%lld\n",(ans[i]>(1ll<<55))?-1ll:ans[i]);
}
