
def getBiggestRegion(grid, n, m):
    max_region = 0
    region_size = 0
    for i in xrange(n):
        for j in xrange(m):
            if grid[i][j] == 1:
                region_size = mark_region(grid, i, j, n, m)
                #region_size += 1
                if region_size > max_region:
                    max_region = region_size
    return max_region


def push_if_valid(stack, i, j, n, m):
    if 0 <= i < n and 0 <= j < m:
        stack.append((i, j))

dirs = [[1,0], [0,1], [-1,0], [0,-1], [-1,-1], [-1, 1], [1,1], [1, -1]]
def mark_region(grid, i, j, n, m):
    stack = []
    stack.append((i, j))
    region_size = 0
    while stack:
        curr = stack.pop()
        ci = curr[0]
        cj = curr[1]
        if grid[ci][cj] == 1:
            grid[ci][cj] = 2
            region_size += 1
            for dir in dirs:
                push_if_valid(stack, ci + dir[0], cj + dir[1], n, m)

    return region_size

n = int(raw_input().strip())
m = int(raw_input().strip())
grid = []
for grid_i in xrange(n):
    grid_t = list(map(int, raw_input().strip().split(' ')))
    grid.append(grid_t)
print(getBiggestRegion(grid, n, m))

