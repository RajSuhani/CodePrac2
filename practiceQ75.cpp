#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;
    int dp[205][201][201];

    int solve(int idx, int g1, int g2, vector<int>& nums) {
        if (idx == nums.size())
            return (g1 > 0 && g2 > 0 && g1 == g2);

        int &res = dp[idx][g1][g2];
        if (res != -1) return res;

        long long ans = 0;

        ans += solve(idx + 1, g1, g2, nums);

        ans += solve(idx + 1, gcd(g1, nums[idx]), g2, nums);

        ans += solve(idx + 1, g1, gcd(g2, nums[idx]), nums);

        return res = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};