#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    int bestIndex;

    TrieNode() {

        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }

        bestIndex = -1;
    }
};

class Solution {
public:

    void updateBest(TrieNode* node,
                    vector<string>& wordsContainer,
                    int idx) {

        if (node->bestIndex == -1 ||
            wordsContainer[idx].size() <
            wordsContainer[node->bestIndex].size()) {

            node->bestIndex = idx;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        TrieNode* root = new TrieNode();

        for (int i = 0; i < wordsContainer.size(); i++) {

            string s = wordsContainer[i];

            reverse(s.begin(), s.end());

            TrieNode* node = root;

            updateBest(node, wordsContainer, i);

            for (char ch : s) {

                int idx = ch - 'a';

                if (!node->child[idx]) {
                    node->child[idx] = new TrieNode();
                }

                node = node->child[idx];

                updateBest(node, wordsContainer, i);
            }
        }

        vector<int> ans;

        for (string q : wordsQuery) {

            reverse(q.begin(), q.end());

            TrieNode* node = root;

            int best = root->bestIndex;

            for (char ch : q) {

                int idx = ch - 'a';

                if (!node->child[idx]) {
                    break;
                }

                node = node->child[idx];

                best = node->bestIndex;
            }

            ans.push_back(best);
        }

        return ans;
    }
};

int main() {

    int n, m;

    cin >> n;

    vector<string> wordsContainer(n);

    for (int i = 0; i < n; i++) {
        cin >> wordsContainer[i];
    }

    cin >> m;

    vector<string> wordsQuery(m);

    for (int i = 0; i < m; i++) {
        cin >> wordsQuery[i];
    }

    Solution obj;

    vector<int> ans =
        obj.stringIndices(wordsContainer, wordsQuery);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}