import numpy as np


def cnt_islands(mat, M, N):
    island_cnt = 0
    print('cnt islands, M, N is: ', M, N)
    for i in range(M):
        for j in range(N):
            if mat[i][j] == 1:
                mark_island(mat, i, j, M, N)
                island_cnt += 1
    return island_cnt


def push_if_valid(stack, i, j, M, N):
    if 0 <= i < M and 0 <= j < N:
        stack.append((i, j))


def mark_island(mat, i, j, M, N):
    stack = []
    stack.append((i, j))
    while stack:
        curr = stack.pop()
        print ' curr : ', curr
        ci = curr[0]
        cj = curr[1]
        if mat[ci][cj] == 1:
            mat[ci][cj] = 2
            push_if_valid(stack, ci+1, cj, M, N)
            push_if_valid(stack, ci-1, cj, M, N)
            push_if_valid(stack, ci, cj+1, M, N)
            push_if_valid(stack, ci, cj-1, M, N)


def main():
    mat = [[0, 1, 0, 1, 0], [0, 0, 1, 1, 1], [1, 0, 0, 1, 0], [0, 1, 1, 0, 0], [1, 0, 1, 0, 1]]
    (M, N) = np.shape(mat)

    cnt = cnt_islands(mat, M, N)
    print 'num of Islands is: ' , cnt


main()
