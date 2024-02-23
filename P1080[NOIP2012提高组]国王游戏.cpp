#include<bits/stdc++.h>
using namespace std;
int read() {
	char s;
	int k=0,base=1;
	while((s=getchar())!='-'&&s!=EOF&&!(s>='0'&&s<='9'));
	if(s==EOF)exit(0);
	if(s=='-')base=-1,s=getchar();
	while(s>='0'&&s<='9') {
		k=k*10+(s-'0');
		s=getchar();
	}
	return k*base;
}
void write(int x) {
	if(x<0) {
		putchar('-');
		write(-x);
	} else {
		if(x/10)write(x/10);
		putchar(x%10+'0');
	}
}
int n,A,B;
struct node {
	int x,y;
} a[1010];
bool cmp(node aa,node bb) {
	if (aa.x*aa.y==bb.x*bb.y) return aa.y<bb.y;
	return (aa.x*aa.y)<(bb.x*bb.y);
}
int sum[1010];
int ans[1010],ls;
int p[1010],lp;
int m;
int P;
bool Max() {
	int i=1;
	while (p[i]==0&&i<=lp) i++;
	int j=1;
	while (ans[j]==0&&j<=ls) j++;
	if (lp-i+1>ls-j+1) return false;
	if (lp-i+1<ls-j+1) return true;
	while (i<=lp&&j<=ls) {
		if (p[i]<ans[j]) return true;
		if (p[i]>ans[j]) return false;
		i++;
		j++;
	}
	return false;
}
void cheng(int d) {
	for (int i=1; i<=m; i++)
		sum[i]*=a[d].x;
	for (int i=1; i<=m; i++) {
		sum[i+1]+=sum[i]/10000;
		sum[i]%=10000;
	}
	if (sum[m+1]!=0) m++;
}
void div(int d) {
	memset(ans,0,sizeof(ans));
	ls=1;
	while (m>0&&sum[m]==0) m--;
	P=0;
	int flag=0;
	for (int i=m; i>=1; i--) {
		P=P*10000+sum[i];
		ans[++ls]=P/a[d].y;
		if (ans[ls]==0&&!flag) ls--;
		else flag=1;
		P%=a[d].y;
	}
}
int main() {
	n=read();
	A=read();
	B=read();
	for (int i=1; i<=n; i++) a[i].x=read(),a[i].y=read();
	sort(a+1,a+n+1,cmp);
	m=1;
	sum[1]=A;
	for (int i=1; i<=n; i++) {
		div(i);
		if (Max()) {
			lp=ls;
			memcpy(p,ans,sizeof(ans));
		}
		cheng(i);
	}
	int i=0;
	while (i<=lp&&p[i]==0) i++;
	printf("%d",p[i]);
	i++;
	for (; i<=lp; i++) {
		if (0<=p[i]&&p[i]<=9) printf("000%d",p[i]);
		else if (10<=p[i]&&p[i]<=99) printf("00%d",p[i]);
		else if (100<=p[i]&&p[i]<=999) printf("0%d",p[i]);
		else
			printf("%d",p[i]);
	}
	return 0;
}
