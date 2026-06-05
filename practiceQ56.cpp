#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][11][11][3];
    bool vis[20][11][11][3];

    Node dfs(int pos, int prev2, int prev1, int state, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2][prev1][state]) {
            return dp[pos][prev2][prev1][state];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (state == 0) {
                if (d == 0) {
                    Node nxt = dfs(pos + 1, 10, 10, 0, ntight);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                } else {
                    Node nxt = dfs(pos + 1, 10, d, 1, ntight);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                }
            }
            else if (state == 1) {
                Node nxt = dfs(pos + 1, prev1, d, 2, ntight);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else {
                int add = 0;

                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d))
                    add = 1;

                Node nxt = dfs(pos + 1, prev1, d, 2, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + nxt.cnt * add;
            }
        }

        if (!tight) {
            vis[pos][prev2][prev1][state] = true;
            dp[pos][prev2][prev1][state] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, 0, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};