#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {

        if (dp[i] != -1)
            return dp[i];

        int n = arr.size();

        int ans = 1;

        for (int j = i + 1; j <= min(n - 1, i + d); j++) {

            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }

        for (int j = i - 1; j >= max(0, i - d); j--) {

            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, -1);

        int result = 1;

        for (int i = 0; i < n; i++) {
            result = max(result, dfs(i, arr, d, dp));
        }

        return result;
    }
};

int main() {

    int n, d;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> d;

    Solution obj;

    cout << obj.maxJumps(arr, d);

    return 0;
}