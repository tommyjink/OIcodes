#!/usr/bin/env python3
"""Compile C.cpp, check supplied samples, and test against an exact checker.

Usage: python3 C_stress.py --tests 1000 --seed 20261024
The checker itself is verified by exhaustive permutations on small trees.
"""

import argparse
import itertools
import os
from pathlib import Path
import random
import re
import shlex
import subprocess
import zipfile


ROOT = Path(__file__).resolve().parent
WORK = ROOT / ".C_check"


def encode(p):
    return f"{len(p) - 1}\n" + " ".join(map(str, p[2:])) + "\n"


def generate(n, rng, mode):
    p = [0] * (n + 1)
    for i in range(2, n + 1):
        if mode == 0:
            p[i] = rng.randrange(1, i)
        elif mode == 1:
            p[i] = i - 1
        elif mode == 2:
            p[i] = 1
        elif mode == 3:
            p[i] = i // 2
        else:
            p[i] = 1 if i % 3 == 2 else i - 1
    ids = list(range(2, n + 1))
    rng.shuffle(ids)
    ids = [0, 1] + ids
    q = [0] * (n + 1)
    for i in range(2, n + 1):
        q[ids[i]] = ids[p[i]]
    return q


def pairs(p):
    res = []
    n = len(p) - 1
    for i in range(2, n):
        ancestors = set()
        x = i
        while x:
            ancestors.add(x)
            x = p[x]
        for j in range(i + 1, n):
            x = j
            while x not in ancestors:
                x = p[x]
            res.append((i - 1, j - 1, x - 1))
    return res


def score(a, ps):
    return sum((a[i] - a[w]) * (a[j] - a[w]) < 0 for i, j, w in ps)


def run_checker(text, labels, answer=None):
    inp, out = WORK / "current.in", WORK / "current.out"
    inp.write_text(text)
    out.write_text(labels)
    cmd = [str(WORK / "C_checker"), str(inp), str(out)]
    if answer is not None:
        ref = WORK / "current.ans"
        ref.write_text(answer)
        cmd.append(str(ref))
    return subprocess.run(cmd, capture_output=True, text=True, timeout=10)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--tests", type=int, default=1000)
    parser.add_argument("--max-n", type=int, default=80)
    parser.add_argument("--seed", type=int, default=20261024)
    parser.add_argument("--brute-tests", type=int, default=40)
    parser.add_argument("--timeout", type=float, default=5)
    parser.add_argument("--samples", type=Path, default=Path.home() / "Downloads/joseph.zip")
    args = parser.parse_args()
    if not 2 <= args.max_n <= 2000 or min(args.tests, args.brute_tests) < 0 or args.timeout <= 0:
        parser.error("Require 2 <= max-n <= 2000, nonnegative test counts, and positive timeout")
    WORK.mkdir(exist_ok=True)
    compiler = shlex.split(os.environ.get("CXX", "clang++"))
    for name in ("C", "C_checker"):
        subprocess.run(compiler + ["-std=c++17", "-O2", "-I", str(ROOT.parent),
                                   str(ROOT / f"{name}.cpp"), "-o", str(WORK / name)], check=True)
    rng = random.Random(args.seed)

    for t in range(args.brute_tests):
        n = rng.randint(2, 7)
        p = generate(n, rng, t % 5)
        ps = pairs(p)
        best, opt = -1, None
        for a in itertools.permutations(range(1, n + 1)):
            val = score(a, ps)
            if val > best:
                best, opt = val, a
        for a in (opt, rng.sample(range(1, n + 1), n)):
            labels = " ".join(map(str, a)) + "\n"
            result = run_checker(encode(p), labels)
            m = re.search(r"score=(\d+), optimum=(\d+)", result.stdout)
            val = score(a, ps)
            if not m or tuple(map(int, m.groups())) != (val, best) or result.returncode != (val != best):
                raise RuntimeError(f"Checker disagrees with exhaustive search: {result.stdout} {result.stderr}")
    print(f"Checker verified on {args.brute_tests} trees by exhaustive permutations", flush=True)

    cases = [("statement-1", "5\n1 1 3 3\n", "2 1 4 5 3\n"),
             ("statement-2", "6\n1 2 2 1 5\n", "3 5 6 4 1 2\n"),
             ("minimum", "2\n1\n", None),
             ("N-is-internal", "3\n3 1\n", None)]
    if args.samples.exists():
        with zipfile.ZipFile(args.samples) as archive:
            for name in sorted(archive.namelist()):
                if name.endswith(".in"):
                    cases.append((name, archive.read(name).decode(),
                                  archive.read(name[:-3] + ".out").decode()))
    else:
        print(f"Sample archive absent, skipping: {args.samples}", flush=True)
    for mode in range(5):
        cases.append((f"boundary-2000-{mode}", encode(generate(2000, rng, mode)), None))
    for t in range(args.tests):
        n = rng.randint(2, args.max_n)
        cases.append((f"random-{t + 1}", encode(generate(n, rng, t % 5)), None))

    failed = 0
    for t, (name, text, answer) in enumerate(cases, 1):
        try:
            result = subprocess.run([str(WORK / "C")], input=text, capture_output=True,
                                    text=True, timeout=args.timeout)
            labels = result.stdout
            if result.returncode:
                message = f"Runtime error {result.returncode}: {result.stderr}"
            else:
                check = run_checker(text, labels, answer)
                if check.returncode == 2:
                    raise RuntimeError(check.stdout + check.stderr)
                message = "" if check.returncode == 0 else check.stdout.strip()
        except subprocess.TimeoutExpired:
            labels, message = "", "Time limit exceeded"
        if message:
            failed += 1
            if failed <= 5:
                prefix = WORK / f"failure-{failed}"
                prefix.with_suffix(".in").write_text(text)
                prefix.with_suffix(".out").write_text(labels)
                prefix.with_suffix(".txt").write_text(f"{name}: {message}\n")
                print(f"FAIL {name}: {message}; saved to {prefix}.in", flush=True)
        if t <= 9 or t % 200 == 0:
            print(f"[{t}/{len(cases)}] {name}: {'FAIL' if message else 'OK'}", flush=True)
    print(f"Seed {args.seed}: {len(cases) - failed}/{len(cases)} passed; {failed} failed", flush=True)
    return int(failed != 0)


if __name__ == "__main__":
    raise SystemExit(main())
