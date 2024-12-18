#include<bits/stdc++.h>
using namespace std;
double a[110][110];
int n;

bool GE(void){
	
	for(int i=1;i<=n;i++){
		int tmp=i;
		while(tmp<=n&&fabs(a[tmp][i])<1e-6)tmp++;
		if(tmp>n)return 0;
		if(tmp!=i)
			for(int j=1;j<=n+1;j++)
				swap(a[tmp][j],a[i][j]);
		double t=a[i][i];
		for(int j=1;j<=n+1;j++)a[i][j]/=t;
		for(int j=1;j<=n;j++)
			if(j!=i){
				t=a[j][i];
				for(int k=1;k<=n+1;k++)
					a[j][k]-=t*a[i][k];
			}
	}	
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			scanf("%lf",&a[i][j]);	
	if(GE())
		for(int i=1;i<=n;i++)
			printf("%.2lf\n",a[i][n+1]);
	else printf("No Solution\n");
}
