
def is_matched(expression):
    stack = ['end of stack']
    left_match = {')':'(',']':'[','}':'{'}
    for e in expression:
        if e not in left_match or stack[-1]!=matching[e]:
            stack.append(e)
        else:
            stack.pop()
    return stack==['end of stack']

t = int(raw_input().strip())
for a0 in xrange(t):
    expression = raw_input().strip()
    if is_matched(expression) == True:
        print("YES")
    else:
        print("NO")
