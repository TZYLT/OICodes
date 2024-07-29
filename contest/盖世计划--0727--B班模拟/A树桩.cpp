#include<bits/stdc++.h>
using namespace std;
#define M 1001000
__int128 ans=0;
void write(__int128 x){
    vector<char> st;
    while(x)st.push_back(x%10),x/=10;
    while(st.size())putchar(st.back()+'0'),st.pop_back();
}
int sz[M],a[M],n;
int bt[M],st[M];
__int128 b[M],c[M];
int opt1[3]={1,2,2},opt2[3]={0,0,1};
string s;
int main(){
    freopen("wood.in","r",stdin);
    freopen("wood.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    for(int i=0;i<n;i++)
        sz[i]=s[i]-'0';
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++)
        ans+=((__int128)b[i]*(n-i+1));
    //
    for(int r=1;r<=n;r++){
        for(int l=1;l<r;l++)
            if(sz[r]==0)st[l]=opt1[st[l]];
            else st[l]=opt2[st[l]];
        
        if(sz[r]==0)st[r]=opt1[1];
        else st[r]=opt2[1];

        int aans=0;
        for(int l=r;l>=1;l--) {
            aans+=((st[l]==0||st[l]==2)?1:0);
            bt[aans]++;
        } 
    }
    for(int i=1;i<=n;i++)
        ans+=(__int128)b[i]*bt[i];
    write(ans);
}