#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;

        vector<long long> dp(k + 1, 0);
        vector<long long> sum(k + 1, 0);

        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                sum[j] = (sum[j] + dp[j - 1]) % MOD;
            }

            for (int j = 1; j <= k; j++) {
                dp[j] = (dp[j] + sum[j]) % MOD;
            }
        }

        return dp[k];
    }
};