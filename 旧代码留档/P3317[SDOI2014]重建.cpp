#include<bits/stdc++.h>
using namespace std;
double k[301][301],d[301][301],a[301][301];
int n;
double eps=1e-7;
double GE(void){
    double ans=1,w=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;++j){
            while(abs(k[i][i])>eps){
                double d=k[j][i]/k[i][i];
                for(int l=1;l<=n;++l)
                    k[j][l]-=d*k[i][l];
                swap(k[i],k[j]);w=-w;
            }
            swap(k[i],k[j]);w=-w;
        }
    }
    for(int i=1;i<=n;i++)ans*=k[i][i];
    //ans=w*ans;
    return ans;
}

double sum=1;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            double x;scanf("%lf",&x);
            if(i<=j)continue;
            if(x>1-eps)x=1-eps;
            sum*=1-x;
            a[i][j]+=x/(1-x);a[j][i]+=x/(1-x);
            d[i][i]+=x/(1-x);d[j][j]+=x/(1-x);
        }
    

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]-=a[i][j];
    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++)
            k[i-1][j-1]=d[i][j];

    n--;
    printf("%lf",sum*GE());

}