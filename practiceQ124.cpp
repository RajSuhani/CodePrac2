#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;

        int leftRemove = 0, rightRemove = 0;

        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            } 
            else if (c == ')') {
                if (leftRemove > 0) {
                    leftRemove--;
                } else {
                    rightRemove++;
                }
            }
        }

        function<void(int, int, int, string&)> dfs =
            [&](int index, int balance, int lRemove, int rRemove,
                string& current) {

            if (index == s.size()) {
                if (balance == 0 && lRemove == 0 && rRemove == 0) {
                    if (visited.insert(current).second) {
                        ans.push_back(current);
                    }
                }
                return;
            }

            char c = s[index];

            if (c == '(') {
               
                if (lRemove > 0) {
                    dfs(index + 1, balance, lRemove - 1, rRemove, current);
                }

                current.push_back('(');
                dfs(index + 1, balance + 1, lRemove, rRemove, current);
                current.pop_back();
            }
            else if (c == ')') {
                
                if (rRemove > 0) {
                    dfs(index + 1, balance, lRemove, rRemove - 1, current);
                }

                if (balance > 0) {
                    current.push_back(')');
                    dfs(index + 1, balance - 1, lRemove, rRemove, current);
                    current.pop_back();
                }
            }
            else {
               
                current.push_back(c);
                dfs(index + 1, balance, lRemove, rRemove, current);
                current.pop_back();
            }
        };

        string current;
        dfs(0, 0, leftRemove, rightRemove, current);

        return ans;
    }
};