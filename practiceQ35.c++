#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for (int num : nums) {

            vector<int> digits;

            while (num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }

            reverse(digits.begin(), digits.end());

            for (int d : digits) {
                ans.push_back(d);
            }
        }

        return ans;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    vector<int> ans = obj.separateDigits(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}