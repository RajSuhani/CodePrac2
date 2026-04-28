#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for (auto &row : grid) {
            for (int val : row) {
                nums.push_back(val);
            }
        }

        int base = nums[0] % x;
        for (int num : nums) {
            if (num % x != base) return -1;
        }

        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];

        int ops = 0;
        for (int num : nums) {
            ops += abs(num - median) / x;
        }
        
        return ops;
    }
};