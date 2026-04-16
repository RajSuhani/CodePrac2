#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res(n, -1);

        for(auto &p : mp) {
            auto &v = p.second;

            if(v.size() == 1) continue;

            int sz = v.size();

            for(int i = 0; i < sz; i++) {
                int curr = v[i];
                int prev = v[(i - 1 + sz) % sz];
                int next = v[(i + 1) % sz];

                int d1 = abs(curr - prev);
                int d2 = abs(curr - next);

                int dist1 = min(d1, n - d1);
                int dist2 = min(d2, n - d2);

                res[curr] = min(dist1, dist2);
            }
        }

        vector<int> ans;
        for(int q : queries) {
            ans.push_back(res[q]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,3,1,4,1,3,2};
    vector<int> queries = {0,3,5};

    vector<int> result = obj.solveQueries(nums, queries);

    for(int x : result) cout << x << " ";

    return 0;
}