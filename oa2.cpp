#include <iostream>
#include <vector>
#include <string>

const int MOD = 1000000007;

int CountSubsequences(char* s, int N) {
    std::vector<int> lastOccurrence(26, -1);
    std::vector<int> dp(N + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= N; ++i) {
        dp[i] = (2 * dp[i - 1]) % MOD;
        if (lastOccurrence[s[i - 1] - 'a'] != -1) {
            dp[i] = (dp[i] - dp[lastOccurrence[s[i - 1] - 'a']] + MOD) % MOD;
        }
        lastOccurrence[s[i - 1] - 'a'] = i - 1;
    }

    return (dp[N] - 1 + MOD) % MOD;
}

int main() {
    int N;
    std::cin >> N;
    char s[N];
    std::cin >> s;

    int result = CountSubsequences(s, N);
    std::cout << result << std::endl;

    return 0;
}
