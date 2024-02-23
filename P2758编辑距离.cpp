#include<bits/stdc++.h>
using namespace std;
int f[3005][3005],lena,lenb;
char a[3005],b[3005];
int main() {
	scanf("%s %s",a,b);
	lena=strlen(a);
	lenb=strlen(b);
	for(int i=1; i<=lena; i++)f[i][0]=i;
	for(int i=1; i<=lenb; i++)f[0][i]=i;
	for(int i=1; i<=lena; i++)
		for(int j=1; j<=lenb; j++) {
			if(a[i-1]==b[j-1]) {
				f[i][j]=f[i-1][j-1];
				continue;
			}
			f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
		}
	printf("%d\n",f[lena][lenb]);
}
