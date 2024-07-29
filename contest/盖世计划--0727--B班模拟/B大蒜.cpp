#include<bits/stdc++.h>
using namespace std;
int t;
bitset<3005> st[3005][2];
int _map[3005][3005];
int main(){
    //auto stt=clock();
    freopen("garlic.in","r",stdin);
    freopen("garlic.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        m++;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
                _map[i][j+1]=s[j]-'0';
            for(int j=0;j<=1;j++)
                st[i][j].reset();
            st[i][0].set(i,1);
        }
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++)
                if(_map[i][j]==0)
                    st[i][j&1]=st[i][(j-1)&1];
                else {
                    if(i==1)st[i][(j)&1]=st[i+1][(j-1)&1];
                    else if(i==n)st[i][(j)&1]=st[i-1][(j-1)&1];
                    else st[i][(j)&1]=st[i+1][(j-1)&1]|st[i-1][(j-1)&1];
                }
        }
        for(int i=1;i<=n;i++)
            cout<<(int)st[i][m&1].count()<<' ';
        cout<<'\n';
            
    }
    //cerr<<clock()-stt;
}