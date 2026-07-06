from bisect import bisect_right

def min_subsequences(a):
    ends = []
    for x in a:
        pos = bisect_right(ends, x)
        if pos < len(ends):
            ends[pos] = x
        else:
            ends.append(x)
    return len(ends)

a = [1,3,2,4,5]
print(min_subsequences(a)) 