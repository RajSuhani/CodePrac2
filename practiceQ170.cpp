#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        for (auto& item : items) {
            minPrice = min(minPrice, item[1]);
        }

        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int freeItems = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeItems++;
                }
            }

            int gain = 1 + freeItems;

            for (int b = budget; b >= price; b--) {
                if (dp[b - price] != -1) {
                    dp[b] = max(dp[b], dp[b - price] + gain);
                }
            }
        }

        int ans = budget / minPrice;

        for (int spent = 0; spent <= budget; spent++) {
            if (dp[spent] != -1) {
                ans = max(ans, dp[spent] +
                          (budget - spent) / minPrice);
            }
        }

        return ans;
    }
};