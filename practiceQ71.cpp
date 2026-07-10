#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        for (int i = 0, j = 0; i < n; i++) {
            while (j + 1 < n && v[j + 1].first - v[i].first <= maxDiff)
                j++;

            for (int k = i + 1; k <= j; k++) {
                adj[v[i].second].push_back(v[k].second);
                adj[v[k].second].push_back(v[i].second);
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int src = q[0], dst = q[1];

            if (src == dst) {
                ans.push_back(0);
                continue;
            }

            vector<int> dist(n, -1);
            queue<int> qu;
            qu.push(src);
            dist[src] = 0;

            while (!qu.empty()) {
                int u = qu.front();
                qu.pop();

                for (int vtx : adj[u]) {
                    if (dist[vtx] == -1) {
                        dist[vtx] = dist[u] + 1;
                        qu.push(vtx);
                    }
                }
            }

            ans.push_back(dist[dst]);
        }

        return ans;
    }
};