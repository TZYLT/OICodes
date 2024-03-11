/*
 * project: validator
 * creator: Jeslan
 * version: 12/11/2023
 */

#include <bits/stdc++.h>

void error(const char *format, ...) {
	fprintf(stderr, "Invalid input!\n");
	va_list vlist;
	va_start(vlist, format);
	vfprintf(stderr, format, vlist);
	va_end(vlist);
	exit(0);
}

template<typename _Tp = long long>
bool inRange(_Tp num, _Tp L, _Tp R) {
	return num >= L && num <= R;
}

#define get_int(e) \
{ \
	if(scanf("%d", &(e)) != 1) error("expected %s\n", #e); \
}

#define in_range(e, l, r) (((e)<(l)||(r)<(e)) ? error("%s (= %d) out of range [%d, %d]\n", #e, (e), (l), (r)), false : true)

#define expect_int(e, l, r) \
{ \
	get_int(e); \
	in_range(e, l, r); \
}

int main() {
	int n, m;
	expect_int(n, 2, (int)1e5);
	expect_int(m, 1, (int)2e5);
	for(int i = 1; i <= n; ++i) {
		int p;
		expect_int(p, 0, (i > 1 && i < n) ? 1 : 0);
	}
	for(int i = 1; i <= m; ++i) {
		int u, v, w;
		expect_int(u, 1, n);
		expect_int(v, 1, n);
		expect_int(w, 1, 1000);
	}
	return 0;
}
