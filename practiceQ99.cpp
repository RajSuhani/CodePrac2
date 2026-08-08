#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, 0);

        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = m - 1 - j;
        }

        vector<int> ans;
        int pos = 0;
        bool changed = false;

        for (int i = 0; i < m; i++) {
            while (pos < n) {
                if (word1[pos] == word2[i]) {
                    ans.push_back(pos++);
                    break;
                }

                if (!changed && (m - i - 1 <= n - pos - 1) &&
                    suf[pos + 1] >= m - i - 1) {
                    ans.push_back(pos++);
                    changed = true;
                    break;
                }

                pos++;
            }

            if (ans.size() != i + 1)
                return {};
        }

        return ans;
    }
};