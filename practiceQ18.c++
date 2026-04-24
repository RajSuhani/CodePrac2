#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blank = 0;

        for(char ch : moves) {
            if(ch == 'L') left++;
            else if(ch == 'R') right++;
            else blank++;  // '_'
        }

        return abs(left - right) + blank;
    }
};

int main() {
    Solution obj;

    string moves;
    cout << "Enter moves string: ";
    cin >> moves;

    int result = obj.furthestDistanceFromOrigin(moves);

    cout << "Furthest distance from origin: " << result << endl;

    return 0;
}