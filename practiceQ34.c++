#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> dp(n, -1);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            if (dp[i] == -1) continue;

            for (int j = i + 1; j < n; j++) {

                long long diff = (long long)nums[j] - nums[i];

                if (-target <= diff && diff <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};

int main() {

    int n, target;

    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> target;

    Solution obj;

    cout << obj.maximumJumps(nums, target);

    return 0;
}