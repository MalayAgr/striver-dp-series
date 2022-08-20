def climbing_stairs(n: int) -> int:
    prev = 0
    curr = 1

    for _ in range(2, n + 1):
        term = prev + curr
        prev = curr
        curr = term

    return term


if __name__ == "__main__":
    n = 20
    print(climbing_stairs(n))
