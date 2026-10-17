import re
import sys


def parse_problem(s: str):
    # 去除复制时可能出现的空格和换行
    s = "".join(s.split())

    pattern = r"SQUARE-HELL/v1;x=(\d+);N=(\d+);T=(\d+);?"
    match = re.fullmatch(pattern, s)

    if match is None:
        raise ValueError("题目字符串格式错误")

    x = int(match.group(1))
    n = int(match.group(2))
    t = int(match.group(3))

    return x, n, t


def main():
    # print("11")
    problem = input()
    # print("11")
    x, n, t = parse_problem(problem)
    # print("11")
    # 连续平方 T 次后：
    # x_T = x_0 ^ (2^T) mod N
    #
    # pow 在 Python 底层的 C 代码中执行，比写 Python 循环快很多。
    answer = pow(x, 1 << t, n)

    print(answer)


if __name__ == "__main__":
    main()