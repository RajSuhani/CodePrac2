#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    long long modPow(long long base, long long exp) {
        long long res = 1;

        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int, int>> q;
        vector<bool> visited(n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }

        return (int)modPow(2, maxDepth - 1);
    }
};