#include <iostream>
#include <cstring>
using namespace std;
int n, k;
int vis[1005][1005];
int main() {
	cin >> n >> k;
	int x1, y1, x2, y2;
	for(int i = 1; i <= n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		vis[x1 + 1][y1 + 1]++;
		vis[x2 + 1][y2 + 1]++;
		vis[x1 + 1][y2 + 1]--;
		vis[x2 + 1][y1 + 1]--;
	}
	int ans = 0;
	for(int i= 1; i <= 1000; i++) {
		for(int j = 1; j <= 1000; j++) {
			vis[i][j] += vis[i - 1][j] + vis[i][j - 1] - vis[i - 1][j - 1];
			if(vis[i][j] == k) ans++;
		}
	}
	cout<<ans<< endl;
	return 0;
}
