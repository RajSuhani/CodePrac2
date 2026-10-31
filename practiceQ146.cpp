#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dpR(m, vector<long long>(n, 0));
        vector<vector<long long>> dpD(m, vector<long long>(n, 0));

        dpR[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long right = dpR[i][j];
                long long down = dpD[i][j];

                if (grid[i][j] == 1) {
                   
                    if (i + 1 < m) {
                        dpD[i + 1][j] = (dpD[i + 1][j] + right) % MOD;
                    }

                    if (j + 1 < n) {
                        dpR[i][j + 1] = (dpR[i][j + 1] + down) % MOD;
                    }
                } else {
                    long long ways = (right + down) % MOD;

                    if (j + 1 < n) {
                        dpR[i][j + 1] = (dpR[i][j + 1] + ways) % MOD;
                    }

                    if (i + 1 < m) {
                        dpD[i + 1][j] = (dpD[i + 1][j] + ways) % MOD;
                    }
                }
            }
        }

        return (dpR[m - 1][n - 1] + dpD[m - 1][n - 1]) % MOD;
    }
};