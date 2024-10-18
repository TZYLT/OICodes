#include<bits/stdc++.h>
using namespace std;
pair<int,int> dt[200200];
int n;
double dis(pair<int,int> x,pair<int,int> y){
    return sqrt((double)(x.first-y.first)*(x.first-y.first)+(double)(x.second-y.second)*(x.second-y.second));
}
double ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&dt[i].first,&dt[i].second);
    }
    for(int i=1;i<=n+1;i++)
        ans+=dis(dt[i-1],dt[i]);
    printf("%.12lf",ans);
}
