#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n);
        vector<vector<int>> up(17, vector<int>(n));
        vector<int> mask(n);
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = timer++;
            up[0][u] = (p == -1 ? u : p);
            mask[u] = (p == -1 ? 0 : mask[p]) ^ (1 << (s[u] - 'a'));

            for (int j = 1; j < 17; j++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer;
        };

        dfs(0, -1);

        vector<int> bit(n + 1, 0);

        auto add = [&](int idx, int val) {
            for (idx++; idx <= n; idx += idx & -idx) {
                bit[idx] ^= val;
            }
        };

        auto queryPrefix = [&](int idx) {
            int res = 0;
            for (idx++; idx > 0; idx -= idx & -idx) {
                res ^= bit[idx];
            }
            return res;
        };

        for (int u = 0; u < n; u++) {
            add(tin[u], 1 << (s[u] - 'a'));
        }

        auto getMask = [&](int u) {
            return queryPrefix(tin[u]);
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for (int j = 0; j < 17; j++) {
                if (diff & (1 << j)) {
                    u = up[j][u];
                }
            }

            if (u == v) return u;

            for (int j = 16; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                add(tin[u], (1 << (s[u] - 'a')) ^ (1 << (c - 'a')));
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);
                int pathMask = getMask(u) ^ getMask(v) ^ (1 << (s[w] - 'a'));

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};