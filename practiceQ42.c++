#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return -1;
    }
};

int main() {

    int n, m;

    cin >> n;

    vector<int> nums1(n);

    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cin >> m;

    vector<int> nums2(m);

    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    Solution obj;

    cout << obj.getCommon(nums1, nums2);

    return 0;
}