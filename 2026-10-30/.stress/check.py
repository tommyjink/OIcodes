#!/usr/bin/env python3
"""Independent differential tests. Original A.cpp--D.cpp are never edited."""
import argparse
import hashlib
import itertools
import json
import math
import random
import shutil
import subprocess
import time
from decimal import Decimal, ROUND_HALF_UP
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = Path(__file__).resolve().parent
MOD = 10**9
SEED = 20261030


def brute_a(data):
    n, s = data.split()
    if len(s) != int(n):
        return 'error!'
    pos = 1
    for c in s:
        pos += c == 'r'
    return str(pos)


def brute_b(data):
    a = list(map(int, data.split()))
    n, a = a[0], list(zip(a[1::2], a[2::2]))
    ans = 10**30
    for mask in range(1 << n):
        if bin(mask).count('1') > n // 2:
            continue
        w, h = 0, 0
        for i, (x, y) in enumerate(a):
            if mask >> i & 1:
                x, y = y, x
            w += x
            h = max(h, y)
        ans = min(ans, w * h)
    return str(ans)


def value_c(data):
    # A graph vertex represents one rainbow. Edge weights are the least
    # expansion needed for two height-h cross sections to touch. The answer
    # is the minimum bottleneck path between the two endpoint vertices.
    a = list(map(float, data.split()))
    h, t = a[:2]
    circles = list(zip(a[2::2], a[3::2]))
    g = [[math.inf] * 9 for _ in range(9)]
    for i in range(9):
        g[i][i] = 0.0
    if t == 0:
        g[7][8] = g[8][7] = 0.0
    for i, (x, r) in enumerate(circles):
        for j, target in [(7, 0.0), (8, t)]:
            g[i][j] = g[j][i] = max(0.0, math.hypot(x - target, h) - r)
        for j in range(i):
            y, s = circles[j]
            lo = max(0.0, h - r, h - s)
            hi = max(lo, h + abs(x - y))
            for _ in range(75):
                mid = (lo + hi) / 2
                p = math.sqrt(max(0.0, (r + mid - h) * (r + mid + h)))
                q = math.sqrt(max(0.0, (s + mid - h) * (s + mid + h)))
                if p + q >= abs(x - y):
                    hi = mid
                else:
                    lo = mid
            g[i][j] = g[j][i] = hi
    for k in range(9):
        for i in range(9):
            for j in range(9):
                g[i][j] = min(g[i][j], max(g[i][k], g[k][j]))
    return g[7][8]


def brute_c(data):
    return str(Decimal(str(value_c(data))).quantize(Decimal('0.01'), rounding=ROUND_HALF_UP))


def brute_d(data):
    # Enumerate plane rooted trees as balanced push/pop sequences. A newly
    # visited vertex gets the next color; returning must match its parent.
    s = data.strip()
    n = len(s)
    if n % 2 == 0:
        return '0'
    m = (n + 1) // 2
    stack = [s[0]]

    def dfs(pos, used):
        if pos == n:
            return int(used == m and len(stack) == 1)
        ans = 0
        if used < m:
            stack.append(s[pos])
            ans += dfs(pos + 1, used + 1)
            stack.pop()
        if len(stack) > 1 and stack[-2] == s[pos]:
            c = stack.pop()
            ans += dfs(pos + 1, used)
            stack.append(c)
        return ans

    return str(dfs(1, 1) % MOD)


def dp_d(data):
    # Split off the first child and the remaining children of the root.
    s = data.strip()
    n = len(s)
    if n % 2 == 0:
        return '0'
    f = [[0] * n for _ in range(n)]
    for i in range(n):
        f[i][i] = 1
    for size in range(3, n + 1, 2):
        for l in range(n - size + 1):
            r = l + size - 1
            if s[l] == s[r]:
                f[l][r] = sum(f[l+1][k-1] * f[k][r]
                              for k in range(l+2, r+1, 2)
                              if s[k] == s[l]) % MOD
    return str(f[0][n-1])


def c_input(h, t, a):
    return f'{h} {t}\n' + ''.join(f'{x} {r}\n' for x, r in a)


def cases_a(rng):
    yield 'sample1', '6\nllrrlr\n', None
    yield 'sample2', '6\nrrr\n', None
    for m in range(1, 11):
        for a in itertools.product('lr', repeat=m):
            s = ''.join(a)
            yield 'exhaustive', f'{m}\n{s}\n', None
            n = m + 1 if a[0] == 'l' or m == 1 else m - 1
            yield 'wrong_length', f'{n}\n{s}\n', None
    for _ in range(500):
        n, m = rng.randint(1, 99), rng.randint(1, 199)
        yield 'random', f'{n}\n' + ''.join(rng.choices('lr', k=m)) + '\n', None
    for n in [1, 49, 50, 98, 99]:
        for m in [1, n, 199]:
            for c in 'lr':
                yield 'boundary', f'{n}\n{c*m}\n', None


def cases_b(rng):
    yield 'sample', '3\n3 1\n2 2\n4 3\n', None
    yield 'greedy_order', '3\n1 3\n3 2\n3 1\n', None
    yield 'answer_cap', '2\n1000 1000\n1000 1000\n', None
    # Exhaust all inputs with n<=3 and dimensions in [1,3].
    dims = list(itertools.product(range(1, 4), repeat=2))
    for n in range(1, 4):
        for a in itertools.product(dims, repeat=n):
            yield 'exhaustive', str(n)+'\n'+''.join(f'{x} {y}\n' for x,y in a), None
    for _ in range(1800):
        n = rng.randint(1, 10)
        lim = rng.choice([3, 10, 1000])
        a = [(rng.randint(1, lim), rng.randint(1, lim)) for _ in range(n)]
        yield 'random', str(n)+'\n'+''.join(f'{x} {y}\n' for x,y in a), None
    yield 'max_answer', '1000\n'+'1000 1000\n'*1000, '1000000000'


def cases_c(rng):
    yield 'sample', c_input(4, 36, [(i*6, 4) for i in range(7)]), '1.00'
    yield 'rounding', c_input(1, 1, [(0, 1)]*7), '0.41'
    yield 'nested_interval', c_input(1, 10, [(5, 10)]+[(9, 1)]*6), '0.00'
    yield 'gap_after_target', c_input(1, 1, [(0, 10)]+[(100, 1)]*6), '0.00'
    yield 'nan_radius', c_input(5, 10, [(x, 1) for x in [0, 2, 4, 6, 8, 10, 10]]), '4.10'
    yield 'binary_upper_bound', c_input(1, 1, [(10, 1)]*7), '9.05'
    for _ in range(1000):
        h = rng.randint(1, 9900) / 100
        t = rng.randint(1, 1000000) / 100
        a = [(rng.randint(0, 1000000)/100, rng.randint(1, 1000000)/100) for _ in range(7)]
        if rng.randrange(2):
            a = [(rng.random()*t, rng.randint(1, 20000)/100) for _ in range(7)]
        if rng.randrange(2):
            a.sort()
        data = c_input(h, t, a)
        # Avoid numerical ambiguity at an exact half cent.
        val = value_c(data)
        if abs(val * 100 - math.floor(val * 100) - .5) < 1e-7:
            continue
        yield 'random', data, None


def cases_d(rng):
    yield 'sample', 'ABABABA\n', '5'
    for n in range(1, 12):
        for a in itertools.product('AB', repeat=n):
            yield 'exhaustive', ''.join(a)+'\n', None
    for _ in range(1000):
        n = rng.randint(1, 21)
        s = ''.join(rng.choices(rng.choice(['AB', 'ABC', 'ABCDE']), k=n))
        yield 'random', s+'\n', None
    for n in [1, 3, 5, 19, 99, 199, 299]:
        m = (n-1)//2
        ans = str((math.comb(2*m, m)//(m+1)) % MOD)
        for s in ['A'*n, ('AB'*(n//2)+'A')]:
            yield 'catalan', s+'\n', ans
    yield 'even_max', 'A'*300+'\n', '0'
    for _ in range(24):
        m = rng.randint(80, 150)
        stack = [rng.choice('ABC')]
        trace = stack[0]
        used = 1
        while used < m or len(stack) > 1:
            if len(stack) == 1 or (used < m and rng.randrange(2)):
                stack.append(rng.choice('ABC'))
                used += 1
            else:
                stack.pop()
            trace += stack[-1]
        yield 'long_valid_tree', trace+'\n', dp_d(trace)


def save_case(letter, name, data, expected, actual):
    p = OUT / 'counterexamples'
    p.mkdir(exist_ok=True)
    base = p / (letter+'_'+name)
    base.with_suffix('.in').write_text(data)
    base.with_suffix('.expected').write_text(expected+'\n')
    base.with_suffix('.actual').write_text(actual+'\n')


def run(letter):
    start = time.monotonic()
    compiler = shutil.which('g++-15') or shutil.which('g++')
    source = ROOT / (letter+'.cpp')
    digest = hashlib.sha256(source.read_bytes()).hexdigest()
    subprocess.run([compiler, '-std=c++17', '-O2', str(source), '-o', str(OUT/letter)], check=True)
    oracle = globals()['brute_'+letter.lower()]
    gen = globals()['cases_'+letter.lower()]
    rng = random.Random(SEED + ord(letter))
    counts, failures, saved = {}, {}, set()
    max_time = 0.0
    for name, data, expected in gen(rng):
        if expected is None:
            expected = oracle(data)
        before = time.monotonic()
        try:
            p = subprocess.run([str(OUT/letter)], input=data, text=True, capture_output=True, timeout=3)
            actual = p.stdout.strip() if p.returncode == 0 else f'RE ({p.returncode}): '+p.stderr[:300]
        except subprocess.TimeoutExpired:
            actual = 'TIMEOUT (3s)'
        elapsed = time.monotonic() - before
        max_time = max(max_time, elapsed)
        counts[name] = counts.get(name, 0) + 1
        if actual != expected:
            failures[name] = failures.get(name, 0) + 1
            if name not in saved:
                save_case(letter, name, data, expected, actual)
                saved.add(name)
                print(f'{letter} {name}: expected={expected}, actual={actual}', flush=True)
        total = sum(counts.values())
        if total % 1000 == 0:
            print(f'{letter}: tested={total}, failed={sum(failures.values())}', flush=True)
    result = dict(problem=letter, seed=SEED+ord(letter), source_sha256=digest,
                  source_unchanged=hashlib.sha256(source.read_bytes()).hexdigest()==digest,
                  counts=counts, failures=failures, total=sum(counts.values()),
                  failed=sum(failures.values()), seconds=round(time.monotonic()-start, 3),
                  max_process_seconds=round(max_time, 4))
    (OUT/(letter+'_result.json')).write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result), flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('problem', choices=list('ABCD'))
    args = parser.parse_args()
    run(args.problem)
