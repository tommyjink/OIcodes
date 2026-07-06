# C. Rounddog

**时间限制**：2.0 s  
**空间限制**：1024 MB  
**分值**：100 分

## 题目描述

对一个长度为 $m$ 的序列 $A=(a_1,a_2,\ldots,a_m)$，定义：

$$
\operatorname{LIS}(A)=\max\{k\mid \exists\ 1\le i_1<i_2<\cdots<i_k\le m,
\ a_{i_1}<a_{i_2}<\cdots<a_{i_k}\},
$$

$$
\operatorname{LDS}(A)=\max\{k\mid \exists\ 1\le i_1<i_2<\cdots<i_k\le m,
\ a_{i_1}>a_{i_2}>\cdots>a_{i_k}\}.
$$

也就是说，$\operatorname{LIS}$ 为严格最长上升子序列长度，$\operatorname{LDS}$ 为严格最长下降子序列长度。

对任意序列 $A$，定义 $f(A)$ 为最大的非负整数 $k$，满足可以找到 $k$ 个实数 $x_1,x_2,\ldots,x_k$，按顺序追加到 $A$ 的末尾后得到

$$
B=(a_1,a_2,\ldots,a_m,x_1,x_2,\ldots,x_k),
$$

并且满足：

1. $B$ 中所有元素两两不同；
2. $\operatorname{LIS}(B)=\operatorname{LIS}(A)$；
3. $\operatorname{LDS}(B)=\operatorname{LDS}(A)$。

现在给定一个长度为 $n$ 的排列 $P=(P_1,P_2,\ldots,P_n)$。对每个前缀

$$
P^{(i)}=(P_1,P_2,\ldots,P_i),
$$

请计算并输出 $f(P^{(i)})$。

## 输入格式

第一行一个整数 $T$，表示测试数据组数。

接下来每组数据包含两行：

1. 第一行一个整数 $n$；
2. 第二行 $n$ 个整数 $P_1,P_2,\ldots,P_n$，表示一个长度为 $n$ 的排列。

## 输出格式

对每组数据输出一行，包含 $n$ 个整数。第 $i$ 个整数应为 $f(P^{(i)})$。

## 数据范围

对于所有数据：

- $1 \le T \le 10^5$；
- $1 \le n \le 2\cdot 10^5$；
- $1 \le P_i \le n$，且 $P$ 是一个排列；
- 所有测试数据的 $n$ 之和不超过 $2\cdot 10^5$。

## 部分分

仅保留原子任务 2、4、5、6。前三个子任务合计 55 分，主要覆盖暴力、小规模或结构特殊的做法；无附加限制的子任务 6 占 45 分。

| 子任务 | 分值 | 附加限制 |
|---:|---:|---|
| 1 | 15 | $n \le 50$，且所有测试数据的 $n$ 之和不超过 $1000$ |
| 2 | 20 | 对每组数据，整个排列的 $\operatorname{LIS}$ 不超过 $2$ 或整个排列的 $\operatorname{LDS}$ 不超过 $2$ |
| 3 | 20 | 所有测试数据的 $n$ 之和不超过 $5000$ |
| 4 | 45 | 无附加限制 |

## 样例

### 输入样例 1

```text
5
2
1 2
3
1 3 2
4
3 4 1 2
5
2 5 1 3 4
6
3 6 2 1 4 5
```

### 输出样例 1

```text
0 0
0 0 0
0 0 1 0
0 0 1 0 0
0 0 1 2 1 2
```



<div style="page-break-after: always;"></div>

