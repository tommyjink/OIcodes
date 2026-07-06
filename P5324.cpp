#include <bits/stdc++.h>
#include <cstdio>
#define mid ((l + r) >> 1)
#define ls (x << 1)
#define rs (x << 1 | 1)
using namespace std;
typedef long long ll;

int read()
{
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = 1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    return f ? -x : x;
}

void print(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

void ot(int x)
{
    print(x);
    putchar(' ');
}

void prt(int a[], int l, int r)
{
    for (int i = l; i <= r; ++i)
        ot(a[i]);
    putchar('\n');
}

const int N = 150000 * 3 + 10;
int n, m;
struct node
{
    int mi, cnt, ans, ad;
} t[4 * N];
int a[N], buc[N];
int st, lim;

void pushup(int x)
{
    t[x].mi = min(t[ls].mi, t[rs].mi);
    t[x].cnt = (t[ls].mi == t[x].mi ? t[ls].cnt : 0) + (t[rs].mi == t[x].mi ? t[rs].cnt : 0);
    t[x].ans = t[ls].ans + t[rs].ans;
}
void tag(int x, int c)
{
    t[x].mi += c;
    t[x].ans = (t[x].mi == 0) ? t[x].cnt : 0;
    t[x].ad += c;
}
void pushdown(int x)
{
    if (t[x].ad)
    {
        tag(ls, t[x].ad);
        tag(rs, t[x].ad);
        t[x].ad = 0;
    }
}
void build(int x, int l, int r)
{
    if (l == r)
    {
        t[x].cnt = 1;
        t[x].ans = 1;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(x);
}
void upda(int x, int l, int r, int L, int R, int c)
{
    if (L <= l && r <= R)
    {
        tag(x, c);
        return;
    }
    pushdown(x);
    if (L <= mid)
        upda(ls, l, mid, L, R, c);
    if (mid < R)
        upda(rs, mid + 1, r, L, R, c);
    pushup(x);
}
int query(int x, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
        return t[x].ans;
    pushdown(x);
    if (R <= mid)
        return query(ls, l, mid, L, R);
    if (mid < L)
        return query(rs, mid + 1, r, L, R);
    return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
}
void chan(int x, int c)
{
    int k = x - buc[x] + 1 - (c > 0);
    upda(1, 1, lim, k, k, c);
    buc[x] += c;
}

int main()
{
    n = read();
    m = read();
    st = 150000 + 1, lim = 450000 + 5;
    build(1, 1, lim);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
        a[i] += st;
        chan(a[i], 1);
    }
    int p, x;
    while (m--)
    {
        p = read();
        x = read();
        if (p > 0)
        {
            if (a[p] <= st + n) 
                chan(a[p], -1);
            else
            {
                --buc[a[p]];
            }
            a[p] = st + x;
            if (a[p] <= st + n)
            {
                chan(a[p], 1);
            }
            else
            {
                ++buc[a[p]];
            }
        }
        else if (x > 0)
        {
            int pos = st + n;
            if (buc[pos])
                upda(1, 1, lim, pos - buc[pos] + 1, pos, -1);
            --st;
        }
        else
        {
            ++st;
            int pos = st + n;
            if (buc[pos])
                upda(1, 1, lim, pos - buc[pos] + 1, pos, 1);
        }
        printf("%d\n", query(1, 1, lim, st + 1, st + n));
    }
    return 0;
}
