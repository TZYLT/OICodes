#include <bits/stdc++.h>
using namespace std;
#define N 200005
int pre[200005];
void preprocess(){
    int dp[200005];
    for (int i = 1; i < N; i++){
        dp[i] = dp[i / 10] + i % 10;
        pre[i] = pre[i - 1] + dp[i];
    }
}
void solve(){
    int n;
    cin >> n;
    cout << pre[n] << '\n';
}
int main(){
    int t;preprocess();
    scanf("%d",&t);
    while(t--){
        solve();
    }
}