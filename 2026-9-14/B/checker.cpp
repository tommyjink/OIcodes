#include "testlib.h"
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct TestCase {
    int n;
    vector<long long> a;
};

[[noreturn]] static void reject(bool jury, const string& message) {
    if (jury) quitf(_fail, "invalid jury answer: %s", message.c_str());
    quitf(_wa, "%s", message.c_str());
}

static bool feasible(const TestCase& tc) {
    for (int i = 1; i <= tc.n; ++i) {
        if (tc.a[i] > i) return false;
    }
    return true;
}

static void validateOutput(InStream& stream, bool jury, const vector<TestCase>& tests) {
    for (size_t caseId = 0; caseId < tests.size(); ++caseId) {
        const TestCase& tc = tests[caseId];
        if (stream.seekEof()) reject(jury, "unexpected end of file before test case " + to_string(caseId + 1));
        string verdict = stream.readToken();
        if (verdict != "YES" && verdict != "NO") {
            reject(jury, "test case " + to_string(caseId + 1) + ": expected exact token YES or NO");
        }

        bool can = feasible(tc);
        if (verdict == "NO") {
            if (can) reject(jury, "test case " + to_string(caseId + 1) + ": reported NO for a feasible instance");
            continue;
        }

        if (!can) reject(jury, "test case " + to_string(caseId + 1) + ": reported YES for an infeasible instance");
        if (stream.seekEof()) reject(jury, "test case " + to_string(caseId + 1) + ": missing K");
        long long k = stream.readLong();
        long long limit = 1LL * tc.n * (tc.n - 1) / 2;
        if (k < 0 || k > limit) {
            reject(jury, "test case " + to_string(caseId + 1) + ": K is outside the allowed range");
        }

        long long initialSum = 0;
        for (int i = 1; i <= tc.n; ++i) initialSum += tc.a[i];
        long long required = 1LL * tc.n * (tc.n + 1) / 2 - initialSum;
        if (k != required) {
            reject(jury, "test case " + to_string(caseId + 1) + ": K does not match the forced total increment");
        }

        vector<long long> b = tc.a;
        for (long long step = 1; step <= k; ++step) {
            if (stream.seekEof()) {
                reject(jury, "test case " + to_string(caseId + 1) + ": operation list is truncated");
            }
            int id = stream.readInt();
            if (id < 1 || id > tc.n) {
                reject(jury, "test case " + to_string(caseId + 1) + ": operation index is out of range");
            }
            long long x = b[id];
            if (x < 1 || x > tc.n) {
                reject(jury, "test case " + to_string(caseId + 1) + ": selected source value is out of range before operation " + to_string(step));
            }
            ++b[static_cast<int>(x)];
        }

        vector<int> count(tc.n + 1);
        for (int i = 1; i <= tc.n; ++i) {
            if (b[i] < 1 || b[i] > tc.n) {
                reject(jury, "test case " + to_string(caseId + 1) + ": final value is outside 1..n");
            }
            ++count[static_cast<int>(b[i])];
        }
        for (int value = 1; value <= tc.n; ++value) {
            if (count[value] != 1) {
                reject(jury, "test case " + to_string(caseId + 1) + ": final sequence is not a permutation");
            }
        }
    }

    if (!stream.seekEof()) reject(jury, "extra output after the last test case");
}

int main(int argc, char** argv) {
    registerTestlibCmd(argc, argv);

    int T = inf.readInt();
    vector<TestCase> tests;
    tests.reserve(T);
    for (int tc = 0; tc < T; ++tc) {
        int n = inf.readInt();
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) a[i] = inf.readLong();
        tests.push_back({n, std::move(a)});
    }

    validateOutput(ans, true, tests);
    validateOutput(ouf, false, tests);
    quitf(_ok, "accepted");
}
