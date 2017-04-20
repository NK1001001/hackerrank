

def is_magic(arr):
    right = len(arr)
    left = 0
    while right > left:
        mid = (right+left)/2
        if arr[mid] == mid:
            return mid
        if arr[mid] > mid:
            right = mid - 1
        else:
            left = mid + 1

    return -1


def main():

    arr = [-5, -3, 2]

    res = is_magic(arr)
    if res < 0:
        print 'Not found'
    else:
        print 'Magic number found at: ', res


main()
