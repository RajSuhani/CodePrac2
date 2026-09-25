#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;

        auto addSet = [](const set<string>& a, const set<string>& b) {
            set<string> res = a;
            res.insert(b.begin(), b.end());
            return res;
        };

        auto multiply = [](const set<string>& a, const set<string>& b) {
            set<string> res;
            for (const string& x : a) {
                for (const string& y : b) {
                    res.insert(x + y);
                }
            }
            return res;
        };

        function<set<string>()> parseExpression;
        function<set<string>()> parseTerm;
        function<set<string>()> parseFactor;

        parseFactor = [&]() -> set<string> {
            if (expression[pos] == '{') {
                pos++; 

                set<string> res = parseExpression();

                pos++; 
                return res;
            }

            string s(1, expression[pos]);
            pos++;

            return {s};
        };

        parseTerm = [&]() -> set<string> {
            set<string> res = {""};

            while (pos < expression.size() &&
                   expression[pos] != '}' &&
                   expression[pos] != ',') {
                res = multiply(res, parseFactor());
            }

            return res;
        };

        parseExpression = [&]() -> set<string> {
            set<string> res = parseTerm();

            while (pos < expression.size() && expression[pos] == ',') {
                pos++;
                res = addSet(res, parseTerm());
            }

            return res;
        };

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};