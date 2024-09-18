#include<bits/stdc++.h>
using namespace std;
char a[23000000],s[23000000];
int n,p[23000000];
void tran(){
    n=strlen(a);
    int k=0;
    s[k++]='$';
    s[k++]='#';
    for(int i=0;i<n;i++){
        s[k++]=a[i];s[k++]='#';
    }s[k++]='&';
    n=k;
}
void manacher(void){
    int r=0,c=0;
    for(int i=1;i<n;i++){
        if(i<r)p[i]=min(p[(c<<1)-i],p[c]+c-i);
        else p[i]=1;
        while(s[i+p[i]]==s[i-p[i]])p[i]++;
        if(p[i]+i>r)r=p[i]+i,c=i;
    }
}
int main(){
    scanf("%s",a);
    tran();
    manacher();
    int ans=1;
    for(int i=0;i<n;i++)
        ans=max(ans,p[i]);
    printf("%d\n",ans-1);
}