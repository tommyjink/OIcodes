t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    evens = []
    odds = []
    for num in a:
        if num % 2 == 0:
            evens.append(num)
        else:
            odds.append(num)
    # 检查偶数
    if len(evens) >= 2:
        print(evens[0], evens[1])
        continue
    # 检查奇数
    found = False
    # 只需检查相邻的奇数（或前3个，足够）
    for i in range(len(odds)-1):
        x = odds[i]
        y = odds[i+1]
        if (y % x) % 2 == 0:
            print(x, y)
            found = True
            break
    if found:
        continue
    # 若相邻奇数都不满足，检查间隔一个的（如第一个和第三个）
    if len(odds) >= 3:
        x = odds[0]
        y = odds[2]
        if (y % x) % 2 == 0:
            print(x, y)
            found = True
    if found:
        continue
    # 无合法对
    print(-1)