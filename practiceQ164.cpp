#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';
            int previous = last[c];

            if (u != 0 && previous != -1) {
                newParent[u] = previous;
            }

            last[c] = u;

            for (int v : adj[u]) {
                dfs(v);
            }

            last[c] = previous;
        };

        dfs(0);

        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        function<int(int)> calculate = [&](int u) {
            for (int v : newAdj[u]) {
                ans[u] += calculate(v);
            }
            return ans[u];
        };

        calculate(0);

        return ans;
    }
};