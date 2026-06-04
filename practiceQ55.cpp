#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {

        auto waviness = [](int x) {
            string s = to_string(x);
            int cnt = 0;

            for (int i = 1; i + 1 < (int)s.size(); i++) {
                if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                    (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                    cnt++;
                }
            }

            return cnt;
        };

        int ans = 0;

        for (int num = num1; num <= num2; num++) {
            ans += waviness(num);
        }

        return ans;
    }
};