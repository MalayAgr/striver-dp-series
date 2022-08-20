def top_down(arr: list[int], idx: int, dp: dict[int, int]) -> int:
    if idx in dp:
        return dp[idx]

    if idx == 0:
        dp[idx] = arr[idx]
        return dp[idx]

    if idx == 1:
        dp[idx] = max(arr[idx], arr[idx - 1])
        return dp[idx]

    picked = top_down(arr, idx - 2, dp) + arr[idx]
    not_picked = top_down(arr, idx - 1, dp)
    dp[idx] = max(picked, not_picked)

    return dp[idx]


def max_sum_subsequence_top_dow(n: int, arr: list[int]) -> int:
    return top_down(arr, n - 1, {})


def max_sum_subsequence_bottom_up(n: int, arr: list[int]) -> int:
    if n == 1:
        return arr[0]

    dp = [arr[0], max(arr[0], arr[1])]

    for i in range(2, n):
        dp.append(max(dp[i - 2] + arr[i], dp[i - 1]))

    return dp[n - 1]


def max_sum_subsequence_space(n: int, arr: list[int]) -> int:
    if n == 1:
        return arr[0]

    prev1 = max(arr[0], arr[1])
    prev2 = arr[0]

    for i in range(2, n):
        curr = max(prev2 + arr[i], prev1)
        prev2 = prev1
        prev1 = curr

    return prev1


if __name__ == "__main__":
    n = 9
    arr = [1, 2, 3, 1, 3, 5, 8, 1, 9]

    print(max_sum_subsequence_top_dow(n, arr))
    print(max_sum_subsequence_bottom_up(n, arr))
    print(max_sum_subsequence_space(n, arr))
