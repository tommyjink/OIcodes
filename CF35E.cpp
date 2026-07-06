#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define endl "\n"
using namespace std;
const int N = 3e5 + 10;
int n, h[N], l[N], r[N], a[N], tot = 0;
struct evt
{
	int h, typ;
};
vector<evt> v[N];
vector<pii> ans;
multiset<int> s;
signed main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i] >> l[i] >> r[i], a[++tot] = l[i], a[++tot] = r[i];
	sort(a + 1, a + 1 + 2 * n);
	a[0] = -1e15, tot = 0;
	for (int i = 1; i <= 2 * n; i++)
		if (a[i] != a[i - 1])
			a[++tot] = a[i];
	for (int i = 1; i <= n; i++)
	{
		l[i] = lower_bound(a + 1, a + 1 + tot, l[i]) - a;
		r[i] = lower_bound(a + 1, a + 1 + tot, r[i]) - a;
		v[l[i]].push_back((evt){h[i], 1});
		v[r[i]].push_back((evt){h[i], 0});
	}
	for (int i = 1; i <= tot; i++)
	{
		// cout<<i<<"______"<<a[i]<<endl;
		// for(auto j:v[i])cout<<j.h<<" "<<j.typ<<endl;
		int sav = 0, now = 0;
		if (!s.empty())
			sav = *s.rbegin();
		for (auto j : v[i])
		{
			if (j.typ)
				s.insert(j.h);
			else
				s.erase(s.find(j.h));
		}
		if (!s.empty())
			now = *s.rbegin();
		if (sav != now)
		{
			ans.push_back(make_pair(a[i], sav));
			ans.push_back(make_pair(a[i], now));
		}
	}
	cout << ans.size() << endl;
	for (pii i : ans)
		cout << i.first << " " << i.second << endl;
	return 0;
}