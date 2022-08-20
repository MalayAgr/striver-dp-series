def top_down(i: int, j: int, dp: dict[tuple[int, int], int]) -> int:
    key = (i, j)

    if key in dp:
        return dp[key]

    if i == 0 and j == 0:
        return 1

    if i < 0 or j < 0:
        return 0

    left = top_down(i, j - 1, dp)
    up = top_down(i - 1, j, dp)

    dp[key] = left + up

    return dp[key]


def unique_paths_top_down(M: int, N: int) -> int:
    if M == 0 or N == 0:
        return 1

    return top_down(M - 1, N - 1, {})


def unique_paths_bottom_up(M: int, N: int) -> int:
    dp = {}

    for j in range(N):
        dp[(0, j)] = 1

    for i in range(M):
        dp[(i, 0)] = 1

    for i in range(1, M):
        for j in range(1, N):
            dp[(i, j)] = dp[(i - 1, j)] + dp[(i, j - 1)]

    return dp[(M - 1), (N - 1)]


def unique_paths_space(M: int, N: int) -> int:
    row = [1] * N

    for _ in range(1, M):
        temp = [1]

        for j in range(1, N):
            temp.append(row[j] + temp[j - 1])

        row = temp

    return row[N - 1]


if __name__ == "__main__":
    M = 3
    N = 2

    print(unique_paths_top_down(M, N))
    print(unique_paths_bottom_up(M, N))
    print(unique_paths_space(M, N))
