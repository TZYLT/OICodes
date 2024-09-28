#include<bits/stdc++.h>
using namespace std;
map<int,int> st;
int n,x;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x),st[x]++;
    for(auto c:st)
        printf("%d %d\n",c.first,c.second);
}