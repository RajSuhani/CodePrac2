#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum -= nums[i];
            ans[i] = abs(leftSum - totalSum);
            leftSum += nums[i];
        }

        return ans;
    }
};