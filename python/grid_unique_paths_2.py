MOD = 10**9 + 7


def top_down(i, j, mat: list[list[int]], dp: dict[tuple[int, int], int]) -> int:
    key = (i, j)

    if key in dp:
        return dp[key]

    if i == 0 and j == 0:
        return 1 if mat[0][0] == 0 else 0

    if i < 0 or j < 0:
        return 0

    if mat[i][j] == -1:
        return 0

    left = top_down(i, j - 1, mat, dp)
    up = top_down(i - 1, j, mat, dp)

    dp[key] = (left + up) % MOD

    return dp[key]


def unique_paths_top_down(N: int, M: int, mat: list[list[int]]) -> int:
    if M == 0 and N == 0:
        return 1 if mat[0][0] == 0 else 0

    return top_down(N - 1, M - 1, mat, {})


def _init_bottom_up(N: int, M: int, mat: list[list[int]]) -> dict[tuple[int, int], int]:
    dp = {}

    j = 0

    while mat[0][j] != -1:
        dp[(0, j)] = 1
        j += 1

    while j < M:
        dp[(0, j)] = 0
        j += 1

    i = 0

    while mat[i][0] != -1:
        dp[(i, 0)] = 1
        i += 1

    while i < N:
        dp[(i, 0)] = 0
        i += 1

    return dp


def unique_paths_bottom_up(N: int, M: int, mat: list[list[int]]) -> int:
    dp = _init_bottom_up(N, M, mat)

    for i in range(1, N):
        for j in range(1, M):
            if mat[i][j] == 0:
                dp[(i, j)] = (dp[(i - 1, j)] + dp[(i, j - 1)]) % MOD
            else:
                dp[(i, j)] = 0

    return dp[(N - 1, M - 1)]


def _init_row(M: int, mat: list[list[int]]) -> list[int]:
    row = []

    obstacle = False

    for j in range(M):
        if obstacle is True:
            row.append(0)
            continue

        if mat[0][j] == -1:
            obstacle = True
            row.append(0)
            continue

        row.append(1)

    return row


def unique_paths_space(N: int, M: int, mat: list[list[int]]) -> int:
    row = _init_row(M, mat)

    obstacle = False

    for i in range(1, N):

        if obstacle is True:
            temp = [0]
        elif mat[i][0] == -1:
            obstacle = True
            temp = [0]
        else:
            temp = [1]

        for j in range(1, M):
            if mat[i][j] == 0:
                paths = (row[j] + temp[j - 1]) % MOD
            else:
                paths = 0

            temp.append(paths)

        row = temp

    return row[M - 1]


if __name__ == "__main__":
    N, M = 2, 1
    mat = [[1], [0]]

    print(unique_paths_top_down(N, M, mat))
    print(unique_paths_bottom_up(N, M, mat))
    print(unique_paths_space(N, M, mat))
