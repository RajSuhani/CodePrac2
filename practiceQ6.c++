#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0; 
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();

        vector<vector<int>> dp(n, vector<int>(27, INT_MAX));

        dp[0][26] = 0;

        for(int i = 1; i < n; i++) {
            int curr = word[i] - 'A';
            int prev = word[i-1] - 'A';

            for(int j = 0; j <= 26; j++) {
                if(dp[i-1][j] == INT_MAX) continue;

                dp[i][j] = min(dp[i][j],
                               dp[i-1][j] + dist(prev, curr));

                dp[i][prev] = min(dp[i][prev],
                                  dp[i-1][j] + dist(j, curr));
            }
        }

        int ans = INT_MAX;
        for(int j = 0; j <= 26; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string word = "CAKE";

    cout << obj.minimumDistance(word) << endl;

    return 0;
}