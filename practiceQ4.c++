#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto &p : mp) {
            vector<int> &v = p.second;

            if(v.size() < 3) continue;

            for(int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i+2] - v[i]);
                ans = min(ans, dist);
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,2,1,1,3};

    cout << obj.minimumDistance(nums);

    return 0;
}