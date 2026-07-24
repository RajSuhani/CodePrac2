#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;  

        vector<bool> present(MAXX, false);
        for (int x : nums) {
            present[x] = true;
        }

        vector<bool> possible2(MAXX, false);

        for (int a : nums) {
            for (int b : nums) {
                possible2[a ^ b] = true;
            }
        }

        vector<bool> possible3(MAXX, false);

        for (int x = 0; x < MAXX; x++) {
            if (!possible2[x]) continue;

            for (int y : nums) {
                possible3[x ^ y] = true;
            }
        }

        int answer = 0;
        for (bool x : possible3) {
            if (x) answer++;
        }

        return answer;
    }
};