#include<bits/stdc++.h>
using namespace std;
#define M 100100
string a,b,p,t;
int nxt[M];
void kmp(char s[],int *nxt,int n){
    nxt[1]=0;
    for(int i=2;i<=n;i++){
        int p=nxt[i-1];
        while(p!=0){
            if(s[p+1]==s[i])break;
            else p=nxt[p];
        }
        nxt[i]=(s[p+1]==s[i])?p+1:0;
    }
}
char str[300300];
int ans,id;
int main(){
    cin>>a>>b>>p;
    
    for(int i=0;i<=a.size();i++){
    	str[0]=' ';
    	for(int j=1;j<=p.size();j++)
    		str[j]=p[j-1];
    	str[p.size()+1]='#';
		for(int j=0;j<i;j++)
			str[j+p.size()+2]=a[j];
		for(int j=i;j<=i+b.size()-1;j++)
			str[j+p.size()+2]=b[j-i];
		for(int j=i+b.size();j<a.size()+b.size();j++)
			str[j+p.size()+2]=a[j-b.size()];
		
		kmp(str,nxt,p.size()+a.size()+b.size()+2);
		int sum=0;
		for(int j=1;j<=p.size()+a.size()+b.size()+2;j++)
			if(nxt[j]==p.size())sum++;
		if(ans<sum)ans=sum,id=i;
	}
    	
	printf("%d %d\n",ans,id);
	
}
