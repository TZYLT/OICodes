#include<bits/stdc++.h>
using namespace std;
#define M 25
int a[M];
int x[M],y[M];
bool v[M],ans[M],t[M];
int n;
string s(M,' ');
int main(){
    scanf("%d",&n);
    n<<=1;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(!x[a[i]])x[a[i]]=i,t[i]=1;
        else y[a[i]]=i;
    }
    s[n]=0;
    int l=1,r=n;
    while(l<r){
        //while(v[l])l++;
        //while(v[r])r--;
        
        if(t[l]==0||t[r]==1){l++;r--;continue;}
        if(l>=r)break;
        if(a[l]==a[r]){
            printf(":(\n");
            return 0;
        }
        v[l]=1;v[y[a[l]]]=1;
        v[r]=1;v[x[a[r]]]=1;
        s[l]='(';s[y[a[l]]]='(';
        s[r]=')';s[x[a[r]]]=')';
        l++;r--;
        cout<<s<<endl;
    }
    cout<<s<<endl;
    // for(int i=1;i<=n;i++)
    //     if(!ans[i])putchar('(');
    //     else putchar(')');
    // putchar('\n');
}   