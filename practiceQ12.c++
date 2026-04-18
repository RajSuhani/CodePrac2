#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0, temp = n;

        while(temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        return abs(n - rev);
    }
};

int main() {
    Solution obj;

    int n = 25;

    cout << obj.mirrorDistance(n);

    return 0;
}