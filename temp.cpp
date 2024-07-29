#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 100001;
const int NM = 11100101;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch > '9' || ch < '0') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

char s[N],t[N];
int F[NM],n,m,p[N];

int &f(int x,int y) { return F[x * (m + 1) + y + 1]; }

int main() {
    std::scanf("%s\n%s",s + 1,t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    p[1] = 0;
    for(int i = 2, j = 0;i <= m;i++) {
        while(j && t[j + 1] != t[i]) j = p[j];
        if(t[j + 1] == t[i]) j++;
        p[i] = j;
    }
    memset(F,128,sizeof F);
    f(0,0) = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(s[i] == t[j] || s[i] == '?') {
                f(i,j) = f(i - 1,j - 1);
            }
            if(j == m) {
                f(i,j)++;
                for(int k = p[m];k;k = p[k]) f(i,k) = std::max(f(i,k),f(i,j)),printf("[%d]",k);
            }
            printf("%d ",f[i][j]);
        }
        for(int j = 0;j <= m;j++) f(i,0) = std::max(f(i,0),std::max(f(i,j),f(i - 1,j)));
    }
    std::printf("%d\n",f(n,0));
    return 0;
}

