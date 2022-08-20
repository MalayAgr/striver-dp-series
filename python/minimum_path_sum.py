MAX = 10**9


def top_down(i: int, j: int, grid: list[list[int]], dp: dict[tuple[int, int], int]):
    key = (i, j)

    if key in dp:
        return dp[key]

    if i == j == 0:
        return grid[0][0]

    if i < 0 or j < 0:
        return MAX

    left = top_down(i, j - 1, grid, dp)
    up = top_down(i - 1, j, grid, dp)

    dp[key] = min(left + grid[i][j], up + grid[i][j])

    return dp[key]


def minimum_path_sum_top_down(N: int, M: int, grid: list[list[int]]) -> int:
    return top_down(N - 1, M - 1, grid, {})


def minimum_path_sum_bottom_up(N: int, M: int, grid: list[list[int]]) -> int:
    dp = {}

    dp[(0, 0)] = grid[0][0]

    for j in range(1, M):
        dp[(0, j)] = dp[(0, j - 1)] + grid[0][j]

    for i in range(1, N):
        dp[(i, 0)] = dp[(i - 1, 0)] + grid[i][0]

    for i in range(1, N):
        for j in range(1, M):
            val = grid[i][j]
            dp[(i, j)] = min(val + dp[(i - 1, j)], val + dp[(i, j - 1)])

    return dp[(N - 1, M - 1)]


def minimum_path_sum_space(N: int, M: int, grid: list[list[int]]) -> int:
    corner = grid[0][0]
    row = [corner]

    for j in range(1, M):
        row.append(row[j - 1] + grid[0][j])

    for i in range(1, N):
        temp = [row[0] + grid[i][0]]

        for j in range(1, M):
            val = grid[i][j]
            min_sum = min(val + row[j], val + temp[j - 1])
            temp.append(min_sum)

        row = temp

    return row[M - 1]


if __name__ == "__main__":
    with open("temp.txt") as f:
        t = int(f.readline())

        for _ in range(t):
            N, M = [int(x) for x in f.readline().split()]
            grid = []
            for i in range(N):
                grid.append([int(x) for x in f.readline().split()])

            print(minimum_path_sum_top_down(N, M, grid))
            print(minimum_path_sum_bottom_up(N, M, grid))
            print(minimum_path_sum_space(N, M, grid))
            print()
