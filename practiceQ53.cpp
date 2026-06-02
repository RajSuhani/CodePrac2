#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {
                int waterStart = max(landFinish, waterStartTime[j]);
                int finishTime = waterStart + waterDuration[j];
                ans = min(ans, finishTime);
            }
        }

        for (int j = 0; j < m; j++) {
            int waterFinish = waterStartTime[j] + waterDuration[j];

            for (int i = 0; i < n; i++) {
                int landStart = max(waterFinish, landStartTime[i]);
                int finishTime = landStart + landDuration[i];
                ans = min(ans, finishTime);
            }
        }

        return ans;
    }
};