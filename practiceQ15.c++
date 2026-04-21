#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa != pb) parent[pa] = pb;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        for(auto &e : allowedSwaps) {
            unite(e[0], e[1]);
        }

        unordered_map<int, vector<int>> groups;

        for(int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int ans = 0;

        for(auto &g : groups) {
            unordered_map<int, int> freq;

            for(int idx : g.second) {
                freq[source[idx]]++;
            }

            for(int idx : g.second) {
                if(freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> source = {1,2,3,4};
    vector<int> target = {2,1,4,5};
    vector<vector<int>> swaps = {{0,1},{2,3}};

    cout << obj.minimumHammingDistance(source, target, swaps);

    return 0;
}