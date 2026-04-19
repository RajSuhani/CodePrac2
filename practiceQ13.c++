#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = 0;

        while(i < n1 && j < n2) {
            if(nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {55,30,5,4,2};
    vector<int> nums2 = {100,20,10,10,5};

    cout << obj.maxDistance(nums1, nums2);

    return 0;
}