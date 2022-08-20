def top_down(
    day: int,
    last_act: int,
    merits: list[list[int]],
    dp: dict[tuple[int, int], int],
) -> int:
    maximum = 0

    if day == 0:
        for idx, merit in enumerate(merits[day]):
            if idx != last_act and merit > maximum:
                maximum = merit

        return maximum

    for idx, merit in enumerate(merits[day]):
        if idx != last_act:
            key = (day, idx)
            if key in dp:
                max_merit = dp[key]
            else:
                max_merit = top_down(day - 1, idx, merits, dp) + merit
                dp[key] = max_merit

            if max_merit > maximum:
                maximum = max_merit

    return maximum


def max_merit_top_down(days: int, merits: list[list[int]]) -> int:
    n_activities = len(merits[0])
    return top_down(days - 1, n_activities, merits, {})


def max_merit_bottom_up(days: int, merits: list[list[int]]) -> int:
    n_activities = len(merits[0])

    dp = [[-1] * n_activities for _ in range(days)]

    for idx, merit in enumerate(merits[0]):
        dp[0][idx] = merit

    for i in range(1, days):
        for j in range(n_activities):
            k = 0
            maximum = 0

            while k < n_activities:
                if k != j:
                    max_merit = dp[i - 1][k] + merits[i][j]

                    if max_merit > maximum:
                        maximum = max_merit

                k += 1

            dp[i][j] = maximum

    return max(dp[days - 1])


def max_merit_space(days: int, merits: list[list[int]]) -> int:
    n_activities = len(merits[0])

    row = []

    for merit in merits[0]:
        row.append(merit)

    for i in range(1, days):
        new_row = []
        for j in range(n_activities):
            k = 0
            maximum = 0

            while k < n_activities:
                if k != j:
                    max_merit = row[k] + merits[i][j]

                    if max_merit > maximum:
                        maximum = max_merit

                k += 1

            new_row.append(maximum)

        row = new_row

    return max(row)


if __name__ == "__main__":
    days = 3
    merits = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]

    print(max_merit_top_down(days=days, merits=merits))
    print(max_merit_bottom_up(days=days, merits=merits))
    print(max_merit_space(days=days, merits=merits))
