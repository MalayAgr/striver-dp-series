def frog_jumpk_table(n: int, K: int, heights: list[int]) -> int:
    dp = [0, abs(heights[0] - heights[1])]

    for i in range(2, n):
        height = heights[i]

        minimum = dp[i - 1] + abs(height - heights[i - 1])
        k = 2

        while k <= min(K, i):
            minimum = min(minimum, dp[i - k] + abs(height - heights[i - k]))
            k += 1

        dp.append(minimum)

    return dp[n - 1]


if __name__ == "__main__":
    n = 6
    k = 2
    heights = [30, 10, 60, 10, 60, 50]

    print(frog_jumpk_table(n, k, heights))
