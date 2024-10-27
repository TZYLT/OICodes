#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
    
    for(int i=1;i<=300;i++){
        freopen(".in","w",stdout);
        //cerr<<i<<endl;
        cout<<i<<endl;
        fclose(stdout);
        system("B.exe");
        freopen(".out","r",stdin);
        int tmp;
        cin>>tmp;
        //freopen("ans.out","w",stdout);
        cerr<<tmp<<',';
        fclose(stdin);
        //fclose(stdout);
    }
}