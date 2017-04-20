
def is_matched(expression):
    stack = ['bottom']
    matching = {')':'(',']':'[','}':'{'}
    for i in matching:
        print i
    for e in expression:
        print stack[-1]
        if e not in matching or stack[-1] != matching[e]:
            stack.append(e)
        else:
            a = stack[-1]
            print a
            b = stack.pop()
            print b
    return stack == ['bottom']

t = int(raw_input().strip())
for a0 in xrange(t):
    expression = raw_input().strip()
    if is_matched(expression) == True:
        print("YES")
    else:
        print("NO")