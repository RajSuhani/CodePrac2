#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long both = min(need1, need2);
        long long extra = max(need1, need2) - both;

        long long ans1 = both * costBoth
                       + (need1 - both) * 1LL * cost1
                       + (need2 - both) * 1LL * cost2;

        long long ans2 = max(need1, need2) * 1LL * costBoth;

        return min(ans1, ans2);
    }
};
