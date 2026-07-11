#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = true;

            vector<int> component;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                component.push_back(u);

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            int sz = component.size();
            bool complete = true;

            for (int node : component) {
                if ((int)adj[node].size() != sz - 1) {
                    complete = false;
                    break;
                }
            }

            if (complete) ans++;
        }

        return ans;
    }
};