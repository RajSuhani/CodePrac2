#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        const long long INF = 1e18;

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));

        dp[0][0] = 0;

        for(int j = 1; j <= m; j++) {
            int pos = factory[j-1][0];
            int limit = factory[j-1][1];

            for(int i = 0; i <= n; i++) {
                dp[i][j] = dp[i][j-1]; 

                long long cost = 0;

                for(int k = 1; k <= limit && k <= i; k++) {
                    cost += abs(robot[i-k] - pos);
                    dp[i][j] = min(dp[i][j],
                                   dp[i-k][j-1] + cost);
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    Solution obj;

    vector<int> robot = {0,4,6};
    vector<vector<int>> factory = {{2,2},{6,2}};

    cout << obj.minimumTotalDistance(robot, factory);

    return 0;
}