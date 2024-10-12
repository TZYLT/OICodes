#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin>>s;
    int n=s.size();
    if(s[n-1]=='n'&&s[n-2]=='a'&&s[n-3]=='s')printf("Yes\n");
    else printf("No\n");
}