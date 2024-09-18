#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long a,b;
vector<__int128> st;
int v[2520];
void dfs(int k,__int128 sum,__int128 n){
    printf("[%d]",k);
    if(k==st.size())return;
    for(int i=0;i<st.size();i++)
        if((sum*st[i]/__gcd(sum,st[i]))<=n){
            if(!v[i]){
                sum=sum*st[i]/__gcd(sum,st[i]);v[i]=1;
                ans+=(k&1)?(n/sum):-(n/sum);
                dfs(k+1,sum,n);
                sum/=st[i];v[i]=0;
            }
        }
        //else return;
}
int main(){
    scanf("%lld%lld",&a,&b);
    int n=0,t=b;
    while(t)n++,t/=10;
    st.push_back(6);
    for(int i=1;i<(1<<(n+1));i++){
        __int128 tk=0;
        for(int j=0;j<n;j++)
            if(i>>j)tk+=((i>>j)&1)?8:6,tk*=10;
        tk/=10;
        if(tk<=b){
            int f=1;
            for(int i=0;i<st.size();i++)
                if(__gcd(st[i],tk)==st[i]||__gcd(st[i],tk)==tk){
                    f=0;
                    printf("[%d:%d]",(long long)st[i],(long long)tk);break;
                }
            if(1)
        }
        st.push_back(tk);
    }
    for(auto c:st)printf("%lld ",(long long)c);

    sort(st.begin(),st.end());
    reverse(st.begin(),st.end());
    long long ansl,ansr;
    dfs(0,1,a-1);
    ansl=ans;ans=0;
    dfs(0,1,b);
    ansr=ans;
    printf("%lld\n",ansl-ansr);
}