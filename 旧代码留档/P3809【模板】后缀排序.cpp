#include<bits/stdc++.h>
using namespace std;
#define M 1001000
int cnt[M],x[M],y[M],sa[M];
int m,n;
void getsa(string &s){
    m=127;n=s.size();
    for(int i=0;i<m;i++)cnt[i]=0;
    for(int i=0;i<n;i++)cnt[x[i]=s[i]]++;
    for(int i=1;i<m;i++)cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--)sa[--cnt[x[i]]]=i;
    for(int k=1;k<=n;k*=2){
        int p=0;
        for(int i=n-k;i<n;i++)y[p++]=i;
        for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
        for(int i=0;i<m;i++)cnt[i]=0;
        for(int i=0;i<n;i++)cnt[x[y[i]]]++;
        for(int i=1;i<m;i++)cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--)sa[--cnt[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(int i=1;i<n;i++)
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
        if(p>=n)break;
        m=p;
    }
}
string s;
int main(){
    getline(cin,s);
    getsa(s);
    for(int i=0;i<n;i++)
        printf("%d ",sa[i]+1);
}