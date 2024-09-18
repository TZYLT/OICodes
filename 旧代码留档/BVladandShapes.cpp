#include<bits/stdc++.h>
using namespace std;
int t,n;
int m[100];
int main(){
    scanf("%d",&t);
    while(t--){
        memset(m,0,sizeof(m));
        scanf("%d",&n);
        bool v=0;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(auto c:s)m[i]+=c-'0';
            if(m[i]!=m[i-1]&&m[i-1]!=0&&m[i]!=0&&v==0)
                printf("TRIANGLE\n"),v=1;
        }
        if(v==0)printf("SQUARE\n");
    }
}