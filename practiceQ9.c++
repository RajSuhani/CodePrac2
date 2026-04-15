#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int diff = abs(i - startIndex);
                int dist = min(diff, n - diff);
                ans = min(ans, dist);
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};

int main() {
    Solution obj;

    vector<string> words = {"hello","i","am","leetcode","hello"};
    string target = "hello";
    int startIndex = 1;

    cout << obj.closestTarget(words, target, startIndex);

    return 0;
}