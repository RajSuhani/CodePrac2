#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        vector<bool> reachable(n, false);

        reachable[0] = true;

        int pre = 0;

        for (int i = 1; i < n; i++) {

            if (i >= minJump && reachable[i - minJump]) {
                pre++;
            }

            if (i > maxJump && reachable[i - maxJump - 1]) {
                pre--;
            }

            if (pre > 0 && s[i] == '0') {
                reachable[i] = true;
            }
        }

        return reachable[n - 1];
    }
};

int main() {

    string s;
    int minJump, maxJump;

    cin >> s;
    cin >> minJump >> maxJump;

    Solution obj;

    if (obj.canReach(s, minJump, maxJump))
        cout << "true";
    else
        cout << "false";

    return 0;
}