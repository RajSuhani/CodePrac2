#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = *max_element(nums.begin(), nums.end());

        if (nums.size() != n + 1)
            return false;

        vector<int> freq(n + 1, 0);

        for (int x : nums) {

            if (x < 1 || x > n)
                return false;

            freq[x]++;
        }

        for (int i = 1; i < n; i++) {
            if (freq[i] != 1)
                return false;
        }

        return freq[n] == 2;
    }
};

int main() {

    int size;
    cin >> size;

    vector<int> nums(size);

    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    Solution obj;

    if (obj.isGood(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}