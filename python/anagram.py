from collections import defaultdict


def is_anagram(a, b):
    dict = defaultdict(lambda: 0)
    for c in a:
        dict[c] += 1

    for c in b:
        dict[c] -= 1
    cnt_of_diff = 0
    for c in dict.keys():
        cnt_of_diff += abs(dict[c])
    return cnt_of_diff

a = raw_input().strip()
b = raw_input().strip()

print(is_anagram(a, b))
