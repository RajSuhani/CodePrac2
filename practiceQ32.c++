#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isPrime(int x) {
        if (x < 2) return false;
        
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            for (int d = 1; d * d <= val; d++) {
                if (val % d == 0) {

                    mp[d].push_back(i);

                    if (d != val / d)
                        mp[val / d].push_back(i);
                }
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        unordered_set<int> usedPrime;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            int steps = dist[i];

            if (i == n - 1)
                return steps;

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = steps + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = steps + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (isPrime(val) && !usedPrime.count(val)) {

                for (int idx : mp[val]) {

                    if (idx != i && dist[idx] == -1) {
                        dist[idx] = steps + 1;
                        q.push(idx);
                    }
                }

                usedPrime.insert(val);
            }
        }

        return -1;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << obj.minJumps(nums);

    return 0;
}