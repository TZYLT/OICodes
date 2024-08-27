#include<bits/stdc++.h>
using namespace std;
long long f[100];
int n;
int main(){
    f[1]=f[2]=1;
    for(int i=3;i<=60;i++)
        f[i]=f[i-1]+f[i-2];
    scanf("%d",&n);
    while(n--){
        long long a,b;
        scanf("%lld %lld",&a,&b);
        vector<long long> pa,pb;
        int ia=60,ib=60;
        while(a!=0&&ia!=0){
            if(f[ia]<a){
                pa.push_back(a);
                a-=f[ia];
            }ia--;
        } pa.push_back(1);
        while(b!=0&&ib!=0){
            if(f[ib]<b){
                pb.push_back(b);
                b-=f[ib];
            }ib--;
        } pb.push_back(1);
        long long last=0;
        while(1)
            if(pa.back()!=pb.back()||pa.empty()||pb.empty()){
                printf("%lld\n",last);
                break;
            }else if(pa.back()==pb.back()){
                last=pa.back();
                pa.pop_back();
                pb.pop_back();
            }
    }
}