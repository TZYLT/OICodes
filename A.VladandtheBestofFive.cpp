#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        int a=0;
        for(auto c:s)
            if(c=='A')
                a++;
        if(a<=2)printf("B\n");
        else printf("A\n");
    }
    
}