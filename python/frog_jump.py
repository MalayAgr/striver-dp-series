def frog_jump_table(n: int, heights: list[int]) -> int:
    dp = [0, abs(heights[0] - heights[1])]

    for i in range(2, n):
        dp.append(
            min(
                dp[i - 1] + abs(heights[i] - heights[i - 1]),
                dp[i - 2] + abs(heights[i] - heights[i - 2]),
            )
        )

    return dp[n - 1]


def frog_jump_no_table(n: int, heights: list[int]) -> int:
    prev1 = abs(heights[0] - heights[1])
    prev2 = 0

    for i in range(2, n):
        step1 = prev1 + abs(heights[i] - heights[i - 1])
        step2 = prev2 + abs(heights[i] - heights[i - 2])
        prev2 = prev1
        prev1 = min(step1, step2)

    return prev1


if __name__ == "__main__":
    n = 4
    heights = [10, 20, 30, 10]

    print(frog_jump_table(n=n, heights=heights))
    print(frog_jump_no_table(n=n, heights=heights))
