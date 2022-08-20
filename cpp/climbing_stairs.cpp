#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int climbing_stairs(int n)
{
    ll prev = 0, curr = 1, term = 0;

    for (size_t i = 2; i <= n; i++)
    {
        term = prev + curr;
        prev = curr;
        curr = term;
    }

    return curr % 10000007;
}

int main(void)
{
    int n = 100;
    cout << climbing_stairs(n);
    return 0;
}
