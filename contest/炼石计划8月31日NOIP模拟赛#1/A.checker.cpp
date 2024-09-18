#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int main(){
    cin>>s;
    for(auto c:s){
        if(c=='1')a.push_back(1);
        else if(c=='c')a.push_back(a[a.size()-1]);
        else {
            for(int i=0;i<=(int)a.size()-3;i++)a[i]--;
            a[a.size()-2]+=a[a.size()-1];
            a.pop_back();
        }for(int c:a)printf("%d ",c);printf("\n");
    }
    
}