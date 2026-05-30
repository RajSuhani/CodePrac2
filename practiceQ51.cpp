#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int mx = 0;
        for (auto &q : queries) {
            mx = max(mx, q[1]);
        }

        vector<int> seg(4 * (mx + 5), 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int pos, int val) -> void {

            if (l == r) {
                seg[node] = val;
                return;
            }

            int mid = (l + r) >> 1;

            if (pos <= mid)
                self(self, node * 2, l, mid, pos, val);
            else
                self(self, node * 2 + 1, mid + 1, r, pos, val);

            seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
        };

        auto query = [&](auto&& self, int node, int l, int r,
                         int ql, int qr) -> int {

            if (ql > r || qr < l)
                return 0;

            if (ql <= l && r <= qr)
                return seg[node];

            int mid = (l + r) >> 1;

            return max(
                self(self, node * 2, l, mid, ql, qr),
                self(self, node * 2 + 1, mid + 1, r, ql, qr)
            );
        };

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(mx + 1);

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {

            auto &q = queries[i];

            if (q[0] == 1) {

                int x = q[1];

                auto rightIt = obstacles.upper_bound(x);
                auto leftIt = prev(rightIt);

                int L = *leftIt;
                int R = *rightIt;

                update(update, 1, 0, mx + 1, R, R - L);

                obstacles.insert(x);

                update(update, 1, 0, mx + 1, x, x - L);
                update(update, 1, 0, mx + 1, R, R - x);
            }
            else {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int left = *prev(it);

                int bestGap =
                    query(query, 1, 0, mx + 1, 0, x);

                bestGap = max(bestGap, x - left);

                ans.push_back(bestGap >= sz);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};