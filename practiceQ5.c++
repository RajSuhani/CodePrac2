#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, pair<int,int>> mp; 

        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if(mp.count(x)) {
                auto &p = mp[x];

                if(p.second != -1) {
                    int dist = 2 * (i - p.first);
                    ans = min(ans, dist);
                }

                p.first = p.second;
                p.second = i;
            } 
            else {
                mp[x] = {-1, i};
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 1, 1, 3};

    int result = obj.minimumDistance(nums);

    cout << "Minimum Distance: " << result << endl;

    return 0;
}