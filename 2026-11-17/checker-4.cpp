#include "testlib.h"
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct Train { int l, r, t, id; };
static void validatePlan(const vector<Train>& a, int n, int m, int k,
                         InStream& stream, bool jury, int tc) {
    const TResult bad = jury ? _fail : _wa;
    if (k == -1) return;
    string s = stream.readToken();
    if ((int)s.size() != m)
        quitf(bad, "Case %d: %s bitstring length is %d, expected %d", tc,
              jury ? "jury" : "participant", (int)s.size(), m);
    int count = 0;
    for (char c : s) {
        if (c != '0' && c != '1') quitf(bad, "Case %d: bitstring contains a non-binary character", tc);
        count += c == '1';
    }
    if (count != k) quitf(bad, "Case %d: reported %d operations, bitstring selects %d", tc, k, count);
    int reach = 1;
    for (const auto& e : a) {
        if (e.l > reach) break;
        reach = max(reach, s[e.id] == '1' ? e.t : e.r);
    }
    if (reach < n) quitf(bad, "Case %d: chosen operations reach only station %d of %d", tc, reach, n);
}
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int T = inf.readInt(1, 100000, "T");
    long long totalM = 0;
    for (int tc = 1; tc <= T; ++tc) {
        int n = inf.readInt(1, 1000000000, "n"), m = inf.readInt(1, 1000000, "m");
        totalM += m;
        if (totalM > 1000000) quitf(_fail, "Input sum(m) exceeds 1000000");
        vector<Train> a(m);
        for (int i = 0; i < m; ++i) {
            int l = inf.readInt(1, n, "l"), r = inf.readInt(l, n, "r"), t = inf.readInt(r, n, "t");
            a[i] = {l, r, t, i};
        }
        sort(a.begin(), a.end(), [](const Train& x, const Train& y) {
            return x.l != y.l ? x.l < y.l : x.id < y.id;
        });
        int expected = ans.readInt(-1, m, "jury_count");
        validatePlan(a, n, m, expected, ans, true, tc);
        if (expected == -1) {
            int reach = 1;
            for (const auto& e : a) {
                if (e.l > reach) break;
                reach = max(reach, e.t);
            }
            if (reach >= n) quitf(_fail, "Case %d: jury says impossible, but all upgrades reach n", tc);
        }
        int found = ouf.readInt(-1, m, "answer_count");
        validatePlan(a, n, m, found, ouf, false, tc);
        if (found != expected) {
            if (found >= 0 && (expected < 0 || found < expected))
                quitf(_fail, "Case %d: a valid participant solution improves the jury answer", tc);
            quitf(_wa, "Case %d: expected minimum %d, found %d", tc, expected, found);
        }
    }
    if (!inf.seekEof()) quitf(_fail, "Unexpected trailing input");
    if (!ans.seekEof()) quitf(_fail, "Unexpected trailing jury output");
    if (!ouf.seekEof()) quitf(_wa, "Unexpected trailing participant output");
    quitf(_ok, "%d cases: all optimal counts and operation plans are valid", T);
}

