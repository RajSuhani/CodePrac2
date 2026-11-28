#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        vector<int> freeCount(n);

        for (int i = 0; i < n; i++) {
            int f = items[i][0];

            int count = 0;
            for (int j = f; j <= n; j += f) {
                count += freq[j];
            }

            freeCount[i] = count - 1;
        }

        vector<pair<long long, long long>> groups;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            if (freeCount[i] > 0 && price < 2 * minPrice) {
                groups.push_back({price, freeCount[i]});
            }
        }

        sort(groups.begin(), groups.end());

        vector<long long> prefCount(1, 0), prefCost(1, 0);

        for (auto [price, count] : groups) {
            prefCount.push_back(prefCount.back() + count);
            prefCost.push_back(prefCost.back() + price * count);
        }

        auto minCost = [&](long long x) -> long long {
            long long q = min(x / 2, prefCount.back());

            if (q == 0) {
                return x * minPrice;
            }

            int idx = lower_bound(
                prefCount.begin() + 1,
                prefCount.end(),
                q
            ) - prefCount.begin();

            long long bonusCost = prefCost[idx - 1]
                + (q - prefCount[idx - 1]) * groups[idx - 1].first;

            return bonusCost + (x - 2 * q) * minPrice;
        };

        long long low = 0;
        long long high = 2LL * budget / minPrice;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (minCost(mid) <= budget) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};