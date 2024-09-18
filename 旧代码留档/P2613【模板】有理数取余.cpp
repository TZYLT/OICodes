#include <bits/stdc++.h>
const int m = 19260817;
inline int getint() {
	int res = 0, ch = getchar();
	while(!isdigit(ch) and ch != EOF)
		ch = getchar();
	while(isdigit(ch)) {
		res = res*10+ (ch - '0');
		res %= m;
		ch = getchar();
	}
	return res;
}
void exgcd(int a, int b,int &x,int &y) {
	if(b == 0) {x = 1;y = 0;return;}
	exgcd(b, a % b,x,y);
	int Last_x = x;
	x = y;
	y = Last_x - a / b * y;
}
int main() {
	int a, b;
	a = getint();
	b = getint();
	if(b == 0) {
		puts("Angry!");
		return 0;
	}
	int x,y;
	exgcd(b, m,x,y);
	x = (x % m + m) % m;
	printf("%lld\n", a * (long long)(x) % m);
	return 0;
}
