#include <cstdio>
#include <cmath>
#include <array>
#include <map>
#include <cstring>
using namespace std;
template <class Type>
void read (Type &x)
{
    char c;
    bool flag = false;
    while ((c = getchar()) < '0' || c > '9')
        c == '-' && (flag = true);
    x = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        x = (x << 1) + (x << 3) + c - '0';
    flag && (x = ~x + 1);
}
template <class Type, class ...rest>
void read (Type &x, rest &...y) { read(x), read(y...); }
template <class Type>
void write (Type x)
{
    x < 0 && (putchar('-'), x = ~x + 1);
    x > 9 && (write(x / 10), 0);
    putchar('0' + x % 10);
}
const int N = 2, M = 3e7 + 10;
typedef long long LL;
typedef array<array<int, N>, N> Matrix;
int p;
Matrix operator * (const Matrix &a, const Matrix &b)
{
    Matrix res;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            res[i][j] = 0;
            for (int k = 0; k < N; ++k)
                res[i][j] = (res[i][j] + (LL)a[i][k] * b[k][j]) % p;
        }
    return res;
}
Matrix binpow (Matrix b, LL k)
{
    Matrix res;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            res[i][j] = i == j;
    for (; k; k >>= 1, b = b * b)
        if (k & 1) res = res * b;
    return res;
}
LL BSGS (Matrix A, Matrix B)
{
    int k = sqrt(p * 6ll) + 1;
    map <Matrix, int> H;
    Matrix s = B;
    for (int i = 0; i < k; ++i, s = s * A) H[s] = i;
    Matrix t = binpow(A, k);
    s = t;
    for (int i = 1; i <= k; ++i, s = s * t)
        if (H.count(s)) return (LL)i * k - H[s];
    return -1;
}
char str[M];
int main ()
{
    scanf("%s", str);
    read(p);
    Matrix A, B;
    A[0][0] = A[0][1] = A[1][0] = 1, A[1][1] = 0;
    B[0][0] = B[1][1] = 1, B[0][1] = B[1][0] = 0;
    LL mod = BSGS(A, B);
    int len = strlen(str);
    LL n = 0;
    for (int i = 0; i < len; ++i)
        n = (n * 10ll + str[i] - '0') % mod;
    write(binpow(A, n)[1][0]);
    return 0;
}