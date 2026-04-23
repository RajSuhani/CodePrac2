#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for(auto &p : mp) {
            vector<int> &v = p.second;
            int k = v.size();

            vector<long long> prefix(k, 0);
            prefix[0] = v[0];

            for(int i = 1; i < k; i++) {
                prefix[i] = prefix[i-1] + v[i];
            }

            for(int i = 0; i < k; i++) {
                long long left = 0, right = 0;

                if(i > 0)
                    left = (long long)i * v[i] - prefix[i-1];

                if(i < k - 1)
                    right = (prefix[k-1] - prefix[i]) - (long long)(k - i - 1) * v[i];

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,3,1,1,2};

    vector<long long> res = obj.distance(nums);

    for(auto x : res) cout << x << " ";

    return 0;
}