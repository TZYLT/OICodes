#include<bits/stdc++.h>
using namespace std;
int t,n,a[200200];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        sort(a+1,a+1+n);
        vector<pair<int,bool> > odd,even;
        for(int i=1;i<=n;i++)
            if(a[i]&1)odd.push_back(make_pair(a[i],0));
            else even.push_back(make_pair(a[i],0));
        if(odd.size()==n||even.size()==n){
            printf("0\n");
            continue;
        }
        while(even.size()){
            int x=odd.back().first;
            while(even.back().second==1)even.pop_back();
            lower_bound(even.begin(),even.end());

        }
    }
}