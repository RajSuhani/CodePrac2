#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        vector<long long> dp(k, 0), ndp(k, 0);

        for (int num : nums) {
            fill(ndp.begin(), ndp.end(), 0);

            int val = num % k;

            ndp[val]++;

            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newR = (long long)r * val % k;
                    ndp[newR] += dp[r];
                }
            }

            dp = ndp;

            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};