#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int iddfs(int t,int lim,vector<int> &a){
    if(t>lim)return 0;
    if(a.size()==1)return 1;
    if(a.size()==2)return 0;

    for(int i=0;i<a.size();i++)
        for(int j=i+1;j<a.size();j++)
            for(int k=j+1;k<a.size();k++) 
                if((a[i]^a[j]^a[k])==0){
                    vector<int> b;
                    for(int p=0;p<=i-1;p++)
                        b.push_back(a[p]);
                    int s=0;
                    for(int p=i;p<=k;p++)
                        s^=a[p];
                    b.push_back(s);
                    for(int p=k+1;p<a.size();p++)
                        b.push_back(a[p]);
                    if(iddfs(t+1,lim,b))return 1;
                }
    return 0;    
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        vector<int> a;
        scanf("%d",&n);
        for(int i=1,x;i<=n;i++)   
            scanf("%d",&x),a.push_back(x);
        for(int i=1;i<=16;i++)
            if(i==16)printf("NO\n");
            else if(iddfs(1,i,a)){
                printf("YES\n");
                break;
            }
    }
}