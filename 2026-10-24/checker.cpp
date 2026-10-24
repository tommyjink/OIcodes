#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    // ---------- 读入输入 ----------
    int N = inf.readInt();
    vector<int> par(N + 1, 0);
    vector<vector<int>> ch(N + 1);
    for (int i = 2; i <= N; i++) {
        par[i] = inf.readInt();
        ch[par[i]].push_back(i);
    }

    // ---------- BFS 求深度 ----------
    vector<int> depth(N + 1, 0);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : ch[u]) {
            depth[v] = depth[u] + 1;
            q.push(v);
        }
    }

    // ---------- 倍增表 ----------
    int LOG = 1;
    while ((1 << LOG) <= N) LOG++;
    vector<vector<int>> up(LOG, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) up[0][i] = par[i];
    for (int k = 1; k < LOG; k++)
        for (int i = 1; i <= N; i++)
            up[k][i] = up[k - 1][up[k - 1][i]];

    auto lca = [&](int u, int v) -> int {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int k = 0; diff; k++, diff >>= 1)
            if (diff & 1) u = up[k][u];
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; k--)
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        return up[0][u];
    };

    // ---------- 预计算 LCA 表：O(N^2 log N) ----------
    vector<vector<int>> lcaTable(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            lcaTable[i][j] = lca(i, j);

    // ---------- 读入选手输出并检查排列 ----------
    vector<int> L(N + 1);
    vector<int> cnt(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        L[i] = ouf.readInt(1, N, format("L[%d]", i));
        cnt[L[i]]++;
    }
    ouf.readEof();  // 不允许多余输出
    for (int x = 1; x <= N; x++)
        if (cnt[x] != 1)
            quitf(_wa, "value %d appears %d times", x, cnt[x]);

    // ---------- 计算目标值 ----------
    // 条件：1 < i,j < N  =>  i,j ∈ [2, N-1]
    // 且 L[i] < L[lca(i,j)] < L[j]
    auto computeCount = [&](const vector<int>& arr) -> long long {
        long long c = 0;
        for (int i = 2; i <= N - 1; i++)
            for (int j = 2; j <= N - 1; j++) {
                if (i == j) continue;
                int w = lcaTable[i][j];
                if (arr[i] < arr[w] && arr[w] < arr[j]) c++;
            }
        return c;
    };

    long long playerCnt = computeCount(L);

    // ---------- 读入标准答案 ----------
    vector<int> SL(N + 1);
    vector<int> scnt(N + 1, 0);
    bool stdValid = true;
    for (int i = 1; i <= N; i++) {
        if (ans.seekEof()) { stdValid = false; break; }
        SL[i] = ans.readInt();
        if (SL[i] < 1 || SL[i] > N) { stdValid = false; break; }
        scnt[SL[i]]++;
    }
    if (stdValid)
        for (int x = 1; x <= N; x++)
            if (scnt[x] != 1) { stdValid = false; break; }

    // 标准答案格式异常时，仅做合法性检查
    if (!stdValid)
        quitf(_ok, "valid labeling, count=%lld (standard unavailable)", playerCnt);

    // ---------- 与标准答案比较最优值 ----------
    long long stdCnt = computeCount(SL);
    if (playerCnt < stdCnt)
        quitf(_wa, "suboptimal: player=%lld, standard=%lld", playerCnt, stdCnt);
    else
        quitf(_ok, "count=%lld", playerCnt);

    return 0;
}