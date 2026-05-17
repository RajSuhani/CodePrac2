#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {

            int idx = q.front();
            q.pop();

            if (arr[idx] == 0)
                return true;

            int forward = idx + arr[idx];
            int backward = idx - arr[idx];

            if (forward < n && !visited[forward]) {
                visited[forward] = true;
                q.push(forward);
            }

            if (backward >= 0 && !visited[backward]) {
                visited[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};

int main() {

    int n, start;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> start;

    Solution obj;

    if (obj.canReach(arr, start))
        cout << "true";
    else
        cout << "false";

    return 0;
}