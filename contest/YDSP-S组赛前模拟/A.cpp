#include<bits/stdc++.h>
using namespace std;
int n;
int a[500100];
int opt[500500];
vector<int> fre;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<n;i++)
        scanf("%d",opt+i);
    for(int i=1;i<=n;i++){
        if(i==1){
            if(opt[i]==1)
                fre.push_back(a[i]);
        }else if(i==n){
            if(opt[i-1]==0)
                fre.push_back(a[i]);
        }else{
            if(opt[i-1]==0&&opt[i]==1)
                fre.push_back(a[i]);
        }
    }
    sort(fre.begin(),fre.end());
    int ans=unique(fre.begin(),fre.end())-fre.begin();
    printf("%d",ans);
}