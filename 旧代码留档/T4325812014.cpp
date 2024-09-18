#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],n;
int main(){
    cin>>n;
    cin>>s;
    if(n%4||n==0){
        printf("No");
        return 0;
    }
    for(auto c:s)
       a[c-'0']++;
    if(a[3]||a[5]||a[6]||a[7]||a[8]||a[9]){
        printf("No");
        return 0;
    }
    else if(a[0]==a[1]&&a[1]==a[2]&&a[1]==a[4]){
        printf("Yes");
        return 0;
    }
}