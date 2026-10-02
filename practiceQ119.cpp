#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int open, int close, int n, string &current,
                   vector<string> &ans) {
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }
        if (open < n) {
            current.push_back('(');
            backtrack(open + 1, close, n, current, ans);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(open, close + 1, n, current, ans);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;

        backtrack(0, 0, n, current, ans);

        return ans;
    }
};