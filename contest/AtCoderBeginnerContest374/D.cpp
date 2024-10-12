#include<bits/stdc++.h>
using namespace std;
int n;
double ans=1e9,s,t;
pair<pair<int,int>,pair<int,int> > line[10];
double dis(double a,double b,double c,double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
    scanf("%d%lf%lf",&n,&s,&t);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&line[i].first.first,&line[i].first.second,&line[i].second.first,&line[i].second.second);
    while(next_permutation(line+1,line+1+n));
    //next_permutation(line+1,line+1+n);
    do{
        for(int i=0;i<(1<<n);i++){
            double c=0;int x=0,y=0;
            for(int j=1;j<=n;j++)
                if((i>>(j-1))&1){
                    c+=(dis(x,y,line[j].first.first,line[j].first.second)/s);
                    c+=(dis(line[j].first.first,line[j].first.second,line[j].second.first,line[j].second.second)/t);
                    x=line[j].second.first,y=line[j].second.second;
                }else{
                    c+=(dis(x,y,line[j].second.first,line[j].second.second)/s);
                    c+=(dis(line[j].first.first,line[j].first.second,line[j].second.first,line[j].second.second)/t);
                    x=line[j].first.first,y=line[j].first.second;
                }
            ans=min(ans,c);
        }
    }while(next_permutation(line+1,line+1+n));
    printf("%.10lf",ans);
}