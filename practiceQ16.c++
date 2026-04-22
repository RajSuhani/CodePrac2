#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for(string &q : queries) {
            for(string &d : dictionary) {
                int diff = 0;

                for(int i = 0; i < q.size(); i++) {
                    if(q[i] != d[i]) diff++;
                }

                if(diff <= 2) {
                    result.push_back(q);
                    break;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dict = {"wood","joke","moat"};

    vector<string> ans = obj.twoEditWords(queries, dict);

    for(auto &s : ans) cout << s << " ";

    return 0;
}