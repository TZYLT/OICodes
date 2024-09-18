// #include<bits/stdc++.h>
// using namespace std;
// int dp[101000];
// int mex(set<int> &a){
//     for(int i=0;i<=100000;i++)
//         if(a.count(i)==0)
//             return i;
// }
// int m=2000;
// int main(){
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         memset(dp,0,sizeof dp);
//         vector<int> opt;
//         for(int j=1;j*j<i;j++)opt.push_back(j);
//         for(int j=1;j*i<=m;j++)
//             opt.push_back(j*i);
//         //printf("[%d]:",i);
//         //for(int c:opt)printf("%d ",c);
//         printf("\n[%d]:",i);
//         for(int j=0;j<=m;j++){
//             set<int> s;
//             for(int c:opt)
//                 if(j-c>=0)s.insert(dp[j-c]);
//             dp[j]=mex(s);
//         }
//         int cnt=0;
//         for(int j=1;j<=m;j++)
//             if(dp[j]!=0)cnt++;
//             else printf("%d ",cnt),cnt=0;
//         printf("\n");
//     }
// }
// #include<bits/stdc++.h>
// using namespace std;
// int t,n;
// int man[501000];
// set<int> s;
// int main(){
//     scanf("%d%d",&t,&n);
//     int k=sqrt((double)n-1);
//     int len=n/__gcd(k+1,n);
//     for(int i=1;i<n;i++)
//         if(i%len==0)man[i]=k+1;
//         else man[i]=k;
    
//     for(int i=1;i<n;i++)
//         man[i]++;
//     for(int i=1;i<n;i++)
//         man[i]+=man[i-1]; 
//     // for(int i=1;i<n;i++)
//     //     printf("%d ",man[i]);
//     s.insert(0);
//     for(int i=1;i<n;i++)
//         s.insert(man[i]);
    
//     while(t--){
//         int x;
//         scanf("%d",&x);
//         if(s.count(x))printf("B");
//         else printf("F");
//     }

// }


#include<bits/stdc++.h>
using namespace std;
int dp[501000];
int t,n,m;
int mex(set<int> &a){
    for(int i=0;i<=501000;i++)
        if(a.count(i)==0)
            return i;
}
int qs[500500];
int main(){
    cin>>t>>n;
    for(int i=1;i<=t;m=max(m,qs[i]),i++)
        cin>>qs[i];
    vector<int> opt;
    for(int j=1;j*j<n;j++)opt.push_back(j);
    for(int j=1;j*n<=m+10;j++)
        opt.push_back(j*n);
    for(int j=1;j<=m;j++){
        set<int> s;
        for(int c:opt)
            if(j-c>=0)s.insert(dp[j-c]);
        dp[j]=mex(s);
    }
    for(int i=1;i<=t;i++){
        if(dp[qs[i]]==0)printf("B");
        else printf("F");
    }
}