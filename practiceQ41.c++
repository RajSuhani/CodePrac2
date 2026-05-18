#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int idx = q.front();
                q.pop();

                if (idx == n - 1)
                    return steps;

                for (int next : mp[arr[idx]]) {

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }

                mp[arr[idx]].clear();

                if (idx + 1 < n && !visited[idx + 1]) {
                    visited[idx + 1] = true;
                    q.push(idx + 1);
                }

                if (idx - 1 >= 0 && !visited[idx - 1]) {
                    visited[idx - 1] = true;
                    q.push(idx - 1);
                }
            }

            steps++;
        }

        return -1;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.minJumps(arr);

    return 0;
}