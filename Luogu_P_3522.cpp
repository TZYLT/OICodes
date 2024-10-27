#include<bits/stdc++.h>
using namespace std;
pair<int,int> q[1000100];
int h=0,t=1;
int n,ans=1;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        while(h-t+1>0&&q[t].first>r)t++;
        if(h-t+1>0)
            ans=max(ans,i-q[t].second+1);
        int tmp=i;
        while(h-t+1>0&&q[h].first<l)tmp=q[h--].second;
        q[++h]={l,tmp};
    }
    printf("%d\n",ans);
}