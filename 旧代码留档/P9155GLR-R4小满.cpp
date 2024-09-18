#include <bits/stdc++.h>
using namespace std;
bitset<200100> h;
int T, t, n, op, d;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        h.reset();
        t = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &op);
            if (op == 1)
            {
                t <<= 1;
                h <<= 1;
                if ((t & (1 << 21)))
                {
                    h[0] = 1;
                    t -= (1 << 21);
                }
            }
            else
            {
                scanf("%d", &d);
                t += d;
                if ((t & (1 << 21)))
                {
                    t -= (1 << 21);
                    for (int j = 0; j <= 150100; j++)
                        if (h[j] == 0)
                        {
                            h[j] = 1;
                            for (int k = 0; k < j; k++)
                                h[k] = 0;
                            break;
                        }
                }
            }
        }
        bool fl = 0;
        int num = 0;
        for (int i = 150100; i >= 0; i--)
        {
            if (fl == 0 && h[i] == 1)
                fl = 1;
            if (fl == 1)
                putchar(h[i] ? '1' : '0'), num++;
        }
        for (int i = 20; i >= 0; i--)
        {
            if (fl == 0 && (t & (1 << i)))
                fl = 1;
            if (fl == 1)
                putchar((t & (1 << i)) ? '1' : '0'), num++;
        }
        if (!num)
            putchar('0');
        putchar('\n');
    }
}