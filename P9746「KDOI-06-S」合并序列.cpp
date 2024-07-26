#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int t,n;
struct tri{int a,b,c;};
vector<tri> path;
int iddfs(int t,int lim,vector<unsigned short> &a){
    //if(t>lim)return 0;
    if(a.size()==1)return 1;
    if(a.size()==2)return 0;
    unsigned short s[505];
    for(int i=0;i<a.size();i++)
        s[i+1]=s[i]^a[i];
    for(int i=0;i<min((n>=400?1:3),(int)a.size());i++){
        for(int j=i+1;j<a.size();j++){
            for(int k=a.size()-1;k>=j+1;k--) 
                if((a[i]^a[j]^a[k])==0){
                    vector<unsigned short> b;
                    for(int p=0;p<=i-1;p++)
                        b.push_back(a[p]);
                    b.push_back(s[i]^s[k+1]);
                    for(int p=k+1;p<a.size();p++)
                        b.push_back(a[p]);
                    path.push_back((tri){i,j,k});
                    if(iddfs(t+1,lim,b))return 1;
                    path.pop_back();
                }
        }
    }
    return 0;    
}
int main(){
    scanf("%d",&t);
    while(t--){
        vector<unsigned short> a;
        scanf("%d",&n);
        for(int i=1,x;i<=n;i++)   
            scanf("%d",&x),a.push_back(x);
        path.clear();
        if(iddfs(1,100,a)){
            printf("Huoyu\n");
            printf("%d\n",path.size());
            for(tri c:path)
                printf("%d %d %d\n",c.a+1,c.b+1,c.c+1);
        } 
        else printf("Shuiniao\n");
    }
}