#include<bits/stdc++.h>
using namespace std;
map<unsigned long long,unsigned long long> m;
unsigned long long t,n,id,s;
int main(){
    scanf("%llu",&t);
    while(t--){
        m.clear();
        scanf("%llu",&n);
        int l=0,d=0;

        while(n--){
            scanf("%llu%llu",&id,&s);
            
            if(m[id]==0){
                if(s==1)l++;
                if(s==2)d++;
            }else if(m[id]==1){
                if(s==2)l--,d++;
                if(s==0)l--;
            }else if(m[id]==2){
                if(s==1)l++,d--;
                if(s==0)d--;
            }
            m[id]=s;
        }
        
        printf("%d %d\n",l,d);
    }
}