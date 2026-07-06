#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
int mp[256][256];
string st, res;
string _s;
char s[100005];
int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);
	// registerLemonChecker(argc, argv);
	mp['A']['D'] = mp['A']['B'] = mp['B']['D'] = mp['B']['A'] = mp['C']['A'] =
		mp['C']['B'] = mp['C']['D'] = 1;
	st = ans.readWord();
	res = ouf.readWord();
	if (st != res)
		quitf(_wa, "wrong YES or NO");
	if (st == "YES") {
		int n = inf.readInt(), m = inf.readInt();
		_s = ouf.readWord();
		if (_s.size() != n)
			quitf(_wa, "wrong length");
		for (int i = 1; i <= n; i++) {
			s[i] = _s[i - 1];
			if (s[i] < 'A' || s[i] > 'D')
				quitf(_wa, "not 'A'~'D'");
		}
		for (int i = 1; i <= m; i++) {
			int u = inf.readInt(), v = inf.readInt(), w = inf.readInt();
			if (mp[s[u]][s[v]] != w)
				quitf(_wa, "wrong construction.");
		}
	}
	quitf(_ok, "Accept.");
}
