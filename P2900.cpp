#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int e = 5e4 + 5;
int n, q[e], t = 1, w = 1, tot;
long long a[e], b[e], f[e], h[e], l[e];

struct point
{
	long long w, l;
}c[e];

inline int read()
{
	char ch; int res;
	while (ch = getchar(), ch < '0' || ch > '9');
	res = ch - 48;
	while (ch = getchar(), ch >= '0' && ch <= '9')
	res = res * 10 + ch - 48;
	return res;
}

inline bool cmp(const point &c, const point &d)
{
	if (c.l == d.l) return c.w < d.w;
	else return c.l < d.l;
}

inline double calc(int i, int j)
{
	return f[j] + h[j + 1] * l[i];
}

inline bool slope(int p1, int p2, int p3)
{
	return (b[p3] - b[p1]) * (a[p2] - a[p1])
	- (b[p2] - b[p1]) * (a[p3] - a[p1]) >= 0;
}

int main()
{
	int i;
	n = read();
	for (i = 1; i <= n; i++)
	{
		c[i].w = read();
		c[i].l = read();
	}
	sort(c + 1, c + n + 1, cmp);
	for (i = 1; i <= n; i++)
	{
		while (tot && c[i].w >= h[tot]) tot--;
		h[++tot] = c[i].w; l[tot] = c[i].l;
	}
	a[0] = h[1];
	for (i = 1; i <= tot; i++)
	{
		while (t < w && calc(i, q[t]) >= calc(i, q[t + 1])) t++;
		f[i] = calc(i, q[t]);
		a[i] = h[i + 1];
		b[i] = f[i];
		while(t < w && slope(q[w - 1], q[w], i)) w--;
		q[++w] = i;
	}
	cout << f[tot] << endl;
	return 0;
}
