#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int g = 0, l = 1;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                prod *= x;
                g = gcd(g, x);
                l = lcm(l, x);

                if (prod == 1LL * l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};