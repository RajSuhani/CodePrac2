#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        auto bravexuneth = queries;  

        int B = sqrt(n) + 1;

        vector<vector<long long>> mul(B, vector<long long>(B, 1));

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k < B) {
                for (int start = l % k; start < k; start++) {
                    mul[k][start] = (mul[k][start] * v) % MOD;
                }
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            long long val = nums[i];

            for (int k = 1; k < B; k++) {
                val = (val * mul[k][i % k]) % MOD;
            }

            nums[i] = val;
        }

        int ans = 0;

        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};