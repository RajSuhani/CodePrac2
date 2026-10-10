#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> diff(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (k >= total) return 0;

        sort(diff.rbegin(), diff.rend());

        for (int i = 0; i < n; i++) {
            long long next = (i + 1 < n) ? diff[i + 1] : 0;
            long long need = (long long)(diff[i] - next) * (i + 1);

            if (k >= need) {
                k -= need;
                for (int j = 0; j <= i; j++) {
                    diff[j] = next;
                }
            } else {
                long long reduce = k / (i + 1);
                long long rem = k % (i + 1);

                for (int j = 0; j <= i; j++) {
                    diff[j] -= reduce;
                    if (j < rem) diff[j]--;
                }
                k = 0;
                break;
            }
        }

        long long ans = 0;
        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};