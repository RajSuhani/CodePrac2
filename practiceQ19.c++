#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<long long>& pos, int k, long long dist) {
        int n = pos.size();

        for (int start = 0; start < n; start++) {
            int count = 1;
            long long last = pos[start];
            
            for (int i = start + 1; i < start + n; i++) {
                long long curr = pos[i % n];

                if (i >= n) curr += pos[n-1] + (pos[0]);
                
                if (curr - last >= dist) {
                    count++;
                    last = curr;
                    if (count >= k) return true;
                }
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;

        for (auto &p : points) {
            long long x = p[0], y = p[1];

            if (y == 0) pos.push_back(x);
            else if (x == side) pos.push_back(side + y);
            else if (y == side) pos.push_back(3LL * side - x);
            else pos.push_back(4LL * side - y);
        }

        sort(pos.begin(), pos.end());

        long long low = 0, high = 2LL * side, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canPlace(pos, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};