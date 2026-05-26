#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_set<char> lower;
        unordered_set<char> upper;

        for (char ch : word) {

            if (islower(ch))
                lower.insert(ch);
            else
                upper.insert(ch);
        }

        int count = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (lower.count(ch) && upper.count(toupper(ch))) {
                count++;
            }
        }

        return count;
    }
};

int main() {

    string word;
    cin >> word;

    Solution obj;

    cout << obj.numberOfSpecialChars(word);

    return 0;
}