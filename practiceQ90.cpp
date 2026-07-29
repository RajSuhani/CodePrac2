#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> half(26, 0);
        int halfLen = s.length() / 2;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
        }

        auto countWays = [&](vector<int>& cnt) {
            long long ways = 1;
            int remaining = halfLen;

            for (int i = 0; i < 26; i++) {
                for (int j = 1; j <= cnt[i]; j++) {
                    ways = ways * remaining / j;
                    remaining--;

                    if (ways >= k) {
                        return (long long)k;
                    }
                }
            }

            return ways;
        };

        if (countWays(half) < k) {
            return "";
        }

        string left = "";

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) {
                    continue;
                }

                half[c]--;


                long long ways = countWays(half);

                if (k > ways) {

                    k -= ways;
                    half[c]++;
                } else {

                    left += char('a' + c);
                    break;
                }
            }
        }

        string middle = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle += char('a' + i);
                break;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};