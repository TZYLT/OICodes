#include<bits/stdc++.h>
using namespace std;
long long t,l,r;
int main(){
    freopen("or.in","r",stdin);
    freopen("or.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&l,&r);
        set<long long> s;
        for(int i=l;i<=r;i++)
            s.insert(i);
        long long last=s.size();
        do{
            vector<long long> tp;
            for(auto c:s)tp.push_back(c);
            for(auto i:tp)
                for(auto j:tp)
                    s.insert(i|j);
            if(s.size()==last)break;
            last=s.size();
        }while(1);
        printf("%lld\n",s.size());
    }
}