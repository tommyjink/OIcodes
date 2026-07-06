import random
import subprocess
from functools import lru_cache

BIN = "/Users/chenghanjin/Documents/CPP/2026-4-11/C"
SRC = "/Users/chenghanjin/Documents/CPP/2026-4-11/C.cpp"


def compile_code():
    cmd = [
        "clang++", SRC,
        "-o", BIN,
        "-std=c++20",
        "-O2",
        "-Wall",
        "-Wextra",
        "-DLOCAL",
    ]
    subprocess.run(cmd, check=True)


def feasible(types, x, y):
    init = tuple([x] * y)

    @lru_cache(None)
    def dfs(i, caps):
        if i == len(types):
            return True
        a, c = types[i]
        if sum(caps) < a:
            return False
        caps = tuple(sorted(caps, reverse=True))

        @lru_cache(None)
        def put(k, rem, state):
            arr = list(state)
            if rem == 0:
                return dfs(i + 1, tuple(sorted(arr, reverse=True)))
            if k == len(arr):
                return False
            mx = min(c, arr[k], rem)
            seen = set()
            for t in range(mx, -1, -1):
                b = arr.copy()
                b[k] -= t
                key = tuple(sorted(b, reverse=True))
                if key in seen:
                    continue
                seen.add(key)
                if put(k + 1, rem - t, key):
                    return True
            return False

        return put(0, a, caps)

    return dfs(0, init)


def brute(n, x, d, a, c, w):
    ans = 0
    for mask in range(1 << n):
        types = []
        val = 0
        tot = 0
        for i in range(n):
            if (mask >> i) & 1:
                types.append((a[i], c[i]))
                val += w[i]
                tot += a[i]
        if not types:
            ans = max(ans, 0)
            continue
        for y in range(1, tot + 1):
            if feasible(types, x, y):
                ans = max(ans, val - y * d)
                break
    return ans


def run_user(inp: str) -> str:
    res = subprocess.run([BIN], input=inp.encode(), stdout=subprocess.PIPE, check=True)
    return res.stdout.decode().strip()


def gen_case():
    n = random.randint(1, 8)
    x = random.randint(1, 8)
    d = random.randint(1, 10)
    a = [random.randint(1, 8) for _ in range(n)]
    c = [random.randint(1, a[i]) for i in range(n)]
    w = [random.randint(1, 20) for _ in range(n)]
    return n, x, d, a, c, w


def main():
    compile_code()
    cas = 0
    while True:
        cas += 1
        n, x, d, a, c, w = gen_case()
        inp = (
            f"1\n"
            f"{n} {x} {d}\n"
            f"{' '.join(map(str, a))}\n"
            f"{' '.join(map(str, c))}\n"
            f"{' '.join(map(str, w))}\n"
        )
        got = run_user(inp)
        exp = str(brute(n, x, d, a, c, w))
        if got != exp:
            print("Mismatch found")
            print(f"case #{cas}")
            print(inp, end="")
            print("your output:", got)
            print("correct   :", exp)
            break
        if cas % 100 == 0:
            print(f"passed {cas} cases")


if __name__ == "__main__":
    main()
