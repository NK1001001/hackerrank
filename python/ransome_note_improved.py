from collections import defaultdict


def ransom_note(mag, ransom):
    word_cnt = defaultdict(lambda:0)
    cnt = 0
    for r in ransom:
        if word_cnt[r] == 0:
            cnt += 1
        word_cnt[r] += 1
    for m in mag:
        if word_cnt[m] > 0:
            word_cnt[m] -= 1
            if word_cnt[m] == 0:
                cnt -= 1
        if cnt == 0:
            return True
    return False


m, n = map(int, raw_input().strip().split(' '))
magazine = raw_input().strip().split(' ')
ransom = raw_input().strip().split(' ')
answer = ransom_note(magazine, ransom)

if answer:
    print "Yes"
else:
    print "No"
