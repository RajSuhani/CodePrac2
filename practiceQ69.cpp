#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> ans;

        for (auto &q : queries) {
            long long x = 0;
            long long sum = 0;

            for (int i = q[0]; i <= q[1]; i++) {
                if (s[i] != '0') {
                    int d = s[i] - '0';
                    x = (x * 10 + d) % MOD;
                    sum += d;
                }
            }

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};