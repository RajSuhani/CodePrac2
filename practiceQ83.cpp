#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] == '1');
        }

        vector<int> start, finish, len;
        vector<char> type;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;

            start.push_back(i);
            finish.push_back(j - 1);
            len.push_back(j - i);
            type.push_back(s[i]);

            i = j;
        }

        int m = start.size();

        vector<int> runId(n);
        for (int i = 0; i < m; i++) {
            for (int j = start[i]; j <= finish[i]; j++) {
                runId[j] = i;
            }
        }

        vector<int> gain(m, 0);

        for (int i = 1; i + 1 < m; i++) {
            if (type[i] == '1' &&
                type[i - 1] == '0' &&
                type[i + 1] == '0') {

                gain[i] = len[i - 1] + len[i + 1];
            }
        }
        int size = 1;
        while (size < m) size <<= 1;

        vector<int> seg(2 * size, 0);

        for (int i = 0; i < m; i++) {
            seg[size + i] = gain[i];
        }

        for (int i = size - 1; i >= 1; i--) {
            seg[i] = max(seg[2 * i], seg[2 * i + 1]);
        }

        auto rangeMax = [&](int l, int r) {
            if (l > r) return 0;

            l += size;
            r += size;

            int res = 0;

            while (l <= r) {
                if (l & 1) res = max(res, seg[l++]);
                if (!(r & 1)) res = max(res, seg[r--]);

                l >>= 1;
                r >>= 1;
            }

            return res;
        };

        vector<int> answer;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int ones = pref[r + 1] - pref[l];

            int leftRun = runId[l];
            int rightRun = runId[r];

            int bestGain = 0;

            int L = leftRun + 1;
            int R = rightRun - 1;

            if (L <= R) {
                bestGain = max(bestGain, rangeMax(L, R));
            }

            if (type[leftRun] == '0') {
                int mid = leftRun + 1;

                if (mid <= rightRun && mid < m && type[mid] == '1') {
                    int rightZero = mid + 1;

                    if (rightZero <= rightRun &&
                        rightZero < m &&
                        type[rightZero] == '0') {

                        int leftZeroLen = finish[leftRun] - l + 1;
                        int rightZeroLen;

                        if (rightZero == rightRun) {
                            rightZeroLen = r - start[rightZero] + 1;
                        } else {
                            rightZeroLen = len[rightZero];
                        }

                        bestGain = max(bestGain,
                                       leftZeroLen + rightZeroLen);
                    }
                }
            }
            if (type[rightRun] == '0') {
                int mid = rightRun - 1;

                if (mid >= leftRun && mid >= 0 &&
                    type[mid] == '1') {

                    int leftZero = mid - 1;

                    if (leftZero >= leftRun &&
                        leftZero >= 0 &&
                        type[leftZero] == '0') {

                        int leftZeroLen;

                        if (leftZero == leftRun) {
                            leftZeroLen = finish[leftZero] - l + 1;
                        } else {
                            leftZeroLen = len[leftZero];
                        }

                        int rightZeroLen = r - start[rightRun] + 1;

                        bestGain = max(bestGain,
                                       leftZeroLen + rightZeroLen);
                    }
                }
            }

            answer.push_back(ones + bestGain);
        }

        return answer;
    }
};