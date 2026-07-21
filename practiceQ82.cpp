#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int initialOnes = count(s.begin(), s.end(), '1');
        int ans = initialOnes;

        // Add virtual '1' at both ends.
        string t = "1" + s + "1";

        // Find lengths of consecutive groups.
        vector<pair<char, int>> groups;

        for (int i = 0; i < (int)t.size(); ) {
            int j = i;
            while (j < (int)t.size() && t[j] == t[i]) {
                j++;
            }
            groups.push_back({t[i], j - i});
            i = j;
        }

        // A valid trade:
        // 1. Choose a 1-block surrounded by 0s.
        // 2. It becomes 0s.
        // 3. This merges the two adjacent 0-blocks.
        // 4. The merged 0-block can be converted to 1s.
        //
        // Net gain = leftZero + oneBlock + rightZero - oneBlock
        //          = leftZero + rightZero
        //
        // So for every internal 1-block, maximize the sum
        // of its neighboring 0-blocks.

        for (int i = 1; i + 1 < (int)groups.size(); i++) {
            if (groups[i].first == '1' &&
                groups[i - 1].first == '0' &&
                groups[i + 1].first == '0') {

                int gain = groups[i - 1].second + groups[i + 1].second;
                ans = max(ans, initialOnes + gain);
            }
        }

        return ans;
    }
};