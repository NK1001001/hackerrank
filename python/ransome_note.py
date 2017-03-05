from collections import defaultdict


def ransom_note(magazine, ransom):

    word_dict = defaultdict(lambda: 0)
    for w in magazine:
        word_dict[w] += 1
    cnt = 0
    for w in ransom:
        if w in word_dict:
            if word_dict[w] > 0:
                word_dict[w] -= 1
                cnt += 1
            else:
                break
    if len(ransom) == cnt:
        return True
    return False