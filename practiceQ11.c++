#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while(x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int rev = reverseNum(nums[i]);

            if(mp.count(rev)) {
                ans = min(ans, i - mp[rev]);
            }

            mp[nums[i]] = i;
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {12,21,45,33,54};

    cout << obj.minMirrorPairDistance(nums);

    return 0;
}