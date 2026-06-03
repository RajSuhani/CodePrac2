#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        auto solve = [&](vector<int>& Astart, vector<int>& Adur,
                         vector<int>& Bstart, vector<int>& Bdur) {

            int m = Bstart.size();

            vector<pair<int,int>> rides;
            for (int i = 0; i < m; i++) {
                rides.push_back({Bstart[i], Bdur[i]});
            }

            sort(rides.begin(), rides.end());

            vector<int> starts(m);
            vector<long long> prefMinDur(m), suffMinOpenFinish(m);

            for (int i = 0; i < m; i++) {
                starts[i] = rides[i].first;
            }

            prefMinDur[0] = rides[0].second;
            for (int i = 1; i < m; i++) {
                prefMinDur[i] = min(prefMinDur[i - 1],
                                    (long long)rides[i].second);
            }

            suffMinOpenFinish[m - 1] =
                (long long)rides[m - 1].first + rides[m - 1].second;

            for (int i = m - 2; i >= 0; i--) {
                suffMinOpenFinish[i] =
                    min(suffMinOpenFinish[i + 1],
                        (long long)rides[i].first + rides[i].second);
            }

            long long best = LLONG_MAX;

            for (int i = 0; i < (int)Astart.size(); i++) {

                long long finishA =
                    (long long)Astart[i] + Adur[i];

                int pos = upper_bound(starts.begin(), starts.end(),
                                      finishA) - starts.begin();

                long long cur = LLONG_MAX;

                if (pos > 0) {
                    cur = min(cur,
                              finishA + prefMinDur[pos - 1]);
                }

                if (pos < m) {
                    cur = min(cur,
                              suffMinOpenFinish[pos]);
                }

                best = min(best, cur);
            }

            return best;
        };

        long long ans1 = solve(landStartTime, landDuration,
                               waterStartTime, waterDuration);

        long long ans2 = solve(waterStartTime, waterDuration,
                               landStartTime, landDuration);

        return (int)min(ans1, ans2);
    }
};