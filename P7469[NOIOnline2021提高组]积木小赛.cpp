#include<bits/stdc++.h>
using namespace std;
#define M 1001000
int nxt[M];
void kmp(string &s){
    nxt[1]=0;
    for(int i=2;i<=s.size();i++){
        int p=nxt[i-1];
        while(p!=0){
            if(s[p+1]==s[i])break;
            else p=nxt[p];
        }
        nxt[i]=(s[p+1]==s[i])?p+1:0;
    }
}