# NOIP 风格模拟赛（二）赛后材料

选手包 `day1.pdf`、四题目录下的 `*.in` 与 `*.ans` 是公开文件；`judge/`、`solutions/` 和 `editorial.md` 仅供赛后使用。

每题 20 个独立测试点、每点 5 分；`judge/manifest.json` 记录来源、路径、输入 SHA-256 摘要。原题的数据文件取自 USACO 已结束竞赛公布的 Test data；T1、T2、T3 每题第 1–5 点由本包的固定种子生成，第 6–20 点对应原赛第 2–16 点。T4 第 1–20 点对应原赛第 4–23 点。两份外部大样例和纸面小样例单独编制，**不参与评测**。

本卷对叙述、文件名和模拟赛分档进行改编，但保持下列原题的核心数学任务与原赛数据约束。来源与官方题解：

| 本卷 | 原题 | 官方题解 |
| --- | --- | --- |
| circle | [Farmer John's Favorite Operation](https://usaco.org/index.php?cpid=1471&page=viewproblem2) | https://usaco.org/current/data/sol_prob2_silver_jan25.html |
| jobs | [Job Completion](https://usaco.org/index.php?cpid=1451&page=viewproblem2) | https://usaco.org/current/data/sol_prob3_gold_dec24.html |
| median | [Median Heap](https://usaco.org/index.php?cpid=1473&page=viewproblem2) | https://usaco.org/current/data/sol_prob1_gold_jan25.html |
| dfs | [DFS Order](https://usaco.org/index.php?cpid=1476&page=viewproblem2) | https://usaco.org/current/data/sol_prob1_platinum_jan25.html |

参考程序为重新实现，使用 C++17 `-O2` 和文件输入输出。命令示例（进入赛后包目录后）：

```bash
python3 tools/judge.py solutions/circle.cpp
python3 tools/judge.py solutions/jobs.cpp
python3 tools/judge.py solutions/median.cpp
python3 tools/judge.py solutions/dfs.cpp
```

本机 `--time-factor` 默认 2；与官方评测硬件不同，超时成绩仅供参考。按各题 `.out` 分词比较答案；程序必须输出指定的 `.out` 文件。
