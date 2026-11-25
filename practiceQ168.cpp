#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        for (int len = 1; len <= n; len++) {
            unordered_map<long long, int> freq;

            long long hash = 0;
            long long power = 1;
            const long long MOD = 1e9 + 7;
            const long long BASE = 31;

            for (int i = 0; i < len; i++) {
                hash = (hash * BASE + nums[i]) % MOD;
                power = (power * BASE) % MOD;
            }

            freq[hash]++;

            for (int i = len; i < n; i++) {
                hash = (hash * BASE + nums[i]
                        - (nums[i - len] * power) % MOD + MOD) % MOD;
                freq[hash]++;
            }

            for (auto& [h, count] : freq) {
                if (count == 1) {
                    return len;
                }
            }
        }

        return n;
    }
};