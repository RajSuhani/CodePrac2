#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        for(auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for(int i = l; i <= r; i += k) {
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }

        int ans = 0;

        for(int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2,3,1,5,4};
    vector<vector<int>> queries = {{1,4,2,3},{0,2,1,2}};

    cout << obj.xorAfterQueries(nums, queries);

    return 0;
}