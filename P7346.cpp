#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N], b[N], c[N], x[N], y[N], tag = 0, nowx = 0, nowy = 0, op[N];
int cnt=0,V[N];

namespace IO {
    const int BUFSIZE = 1 << 20;
    char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
    char obuf[BUFSIZE], *os = obuf, *ot = obuf + BUFSIZE;
    
    inline char getc() {
        if (is == it) it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
        return is == it ? EOF : *is++;
    }
    
    inline void putc(char c) {
        if (os == ot) fwrite(obuf, 1, os - obuf, stdout), os = obuf;
        *os++ = c;
    }
    
    template<typename T>
    inline void read(T &x) {
        x = 0; int f = 1; char c = getc();
        while (!isdigit(c)) { if (c == '-') f = -1; c = getc(); }
        while (isdigit(c)) x = x * 10 + c - '0', c = getc();
        x *= f;
    }
    
    template<typename T>
    inline void write(T x) {
        if (x < 0) putc('-'), x = -x;
        static char stk[20]; int top = 0;
        do { stk[top++] = x % 10 + '0'; } while (x /= 10);
        while (top) putc(stk[--top]);
    }
    
    inline void flush() {
        fwrite(obuf, 1, os - obuf, stdout);
    }
}
using namespace IO;

int get(int x)
{
    int res = a[x];
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i)
            continue;
        res ^= b[i] ^ (tag * c[i]);
        if (i * i != x)
            res ^= b[x / i] ^ (tag * c[x / i]);
    }
    return res;
}

signed main()
{
    read(n); read(m);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i <= m; i++)
    {
        read(op[i]);
        if (op[i] == 1)
        {
            read(x[i]); read(y[i]);
            b[x[i]] ^= y[i];
        }
        else if (op[i] == 2)
        {
            read(x[i]);
            write(get(x[i]));
            putc('\n');
        }
        else if (op[i] == 3)
        {
            int u, v;
            read(x[i]); read(y[i]); read(u); read(v);
            int tmp=(get(x[i]) <= y[i]);
            for (int j=1;j<=cnt;j++)
                b[V[j]] ^= (tag * c[V[j]]), c[V[j]] = 0;
            cnt=0;
            for (int j = u; j <= v; j++)
            {
                if (op[j] == 1)
                {
                    V[++cnt]=x[j];
                    c[x[j]] ^= y[j];
                }
            }
            tag = tmp;
        }
        else if (op[i] == 4)
        {
            int u;
            read(u);
            op[i] = op[u];
            x[i] = x[u];
            y[i] = y[u];
            if (op[i] == 1)
                b[x[i]] ^= y[i];
            else if (op[i] == 2)
            {
                write(get(x[i]));
                putc('\n');
            }
            else if (op[i] == 3)
                if (get(x[i]) <= y[i])
                    tag ^= 1;
        }
    }
    flush();
    return 0;
}