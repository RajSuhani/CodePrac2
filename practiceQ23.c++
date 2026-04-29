#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                pref[j][i + 1] = pref[j][i] + grid[i][j];
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(n + 1, 0));
        
        for (int j = 1; j < n; j++) {
            for (int h = 0; h <= n; h++) {
                for (int ph = 0; ph <= n; ph++) {
                    
                    int low = min(h, ph);
                    int high = max(h, ph);
                    
                    long long gain = pref[j][high] - pref[j][low];
                    
                    dp[j][h] = max(dp[j][h], dp[j - 1][ph] + gain);
                }
            }
        }
        
        long long ans = 0;
        for (int h = 0; h <= n; h++) {
            ans = max(ans, dp[n - 1][h]);
        }
        
        return ans;
    }
};