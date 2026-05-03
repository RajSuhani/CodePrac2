#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        
        string temp = s + s;
        return temp.find(goal) != string::npos;
    }
};

int main() {
    Solution obj;
    
    string s, goal;
    cout << "Enter string s: ";
    cin >> s;
    
    cout << "Enter goal string: ";
    cin >> goal;
    
    if (obj.rotateString(s, goal))
        cout << "True\n";
    else
        cout << "False\n";
    
    return 0;
}