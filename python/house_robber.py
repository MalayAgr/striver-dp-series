##############
## TOP DOWN ##
##############


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


def rob_top_down(arr: list[int], n: int) -> int:
    if n == 1:
        return arr[0]

    with_first = top_down(arr[:-1], n - 2, {})
    with_last = top_down(arr[1:], n - 2, {})

    return max(with_first, with_last)

###############
## BOTTOM UP ##
###############

def bottom_up(arr: list[int], n: int):
    if n == 1:
        return arr[0]

    dp = [arr[0], max(arr[0], arr[1])]

    for i in range(2, n):
        dp.append(max(dp[i - 2] + arr[i], dp[i - 1]))

    return dp[n - 1]


def rob_bottom_up(arr: list[int], n: int) -> int:
    if n == 1:
        return arr[0]

    with_first = bottom_up(arr[:-1], n - 1)
    with_last = bottom_up(arr[1:], n - 1)

    return max(with_first, with_last)


#####################
## SPACE OPTIMIZED ##
#####################

def constant_space(arr: list[int], n: int) -> int:
    if n == 1:
        return arr[0]

    prev1 = max(arr[0], arr[1])
    prev2 = arr[0]

    for i in range(2, n):
        curr = max(prev2 + arr[i], prev1)
        prev2 = prev1
        prev1 = curr

    return prev1


def rob_space(arr: list[int], n: int) -> int:
    if n == 1:
        return arr[0]

    with_first = constant_space(arr[:-1], n - 1)
    with_last = constant_space(arr[1:], n - 1)

    return max(with_first, with_last)


if __name__ == "__main__":
    n = 5
    arr = [1, 5, 2, 1, 6]

    print(rob_top_down(arr, n))
    print(rob_bottom_up(arr, n))
    print(rob_space(arr, n))
