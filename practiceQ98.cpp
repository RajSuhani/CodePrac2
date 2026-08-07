#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // req = required powers of 2,3,5,7
    // Returns true if len digits can provide all required factors.
    bool possible(int len, array<long long, 4> req) {
        long long need2 = (req[0] + 2) / 3; // digit 8 gives 2^3
        long long need3 = (req[1] + 1) / 2; // digit 9 gives 3^2

        // digit 5 and digit 7 each need their own position
        long long need5 = req[2];
        long long need7 = req[3];

        return need2 + need3 + need5 + need7 <= len;
    }

    // Prime factor contribution of a digit.
    array<int, 4> factors(int d) {
        array<int, 4> f = {0, 0, 0, 0};

        while (d % 2 == 0) {
            f[0]++;
            d /= 2;
        }

        while (d % 3 == 0) {
            f[1]++;
            d /= 3;
        }

        while (d % 5 == 0) {
            f[2]++;
            d /= 5;
        }

        while (d % 7 == 0) {
            f[3]++;
            d /= 7;
        }

        return f;
    }

    // Build the lexicographically smallest suffix of exactly len digits
    // whose digit product contains all required prime factors.
    string buildSuffix(int len, array<long long, 4> req) {
        if (!possible(len, req))
            return "";

        string ans;

        for (int pos = 0; pos < len; pos++) {
            for (int d = 1; d <= 9; d++) {
                auto f = factors(d);

                array<long long, 4> nxt = req;

                for (int p = 0; p < 4; p++) {
                    nxt[p] = max(0LL, nxt[p] - (long long)f[p]);
                }

                int remaining = len - pos - 1;

                if (possible(remaining, nxt)) {
                    ans.push_back(char('0' + d));
                    req = nxt;
                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {
        // Factor t into 2, 3, 5, 7.
        array<long long, 4> req = {0, 0, 0, 0};

        long long x = t;

        for (int p = 0; p < 4; p++) {
            int prime = (p == 0 ? 2 :
                         p == 1 ? 3 :
                         p == 2 ? 5 : 7);

            while (x % prime == 0) {
                req[p]++;
                x /= prime;
            }
        }

        // If t has any prime factor other than 2,3,5,7,
        // no digit product can ever be divisible by t.
        if (x != 1)
            return "-1";

        int n = num.size();

        // Check whether num itself works.
        bool zeroFree = true;
        array<long long, 4> remaining = req;

        for (char c : num) {
            int d = c - '0';

            if (d == 0) {
                zeroFree = false;
                break;
            }

            auto f = factors(d);

            for (int p = 0; p < 4; p++) {
                remaining[p] =
                    max(0LL, remaining[p] - (long long)f[p]);
            }
        }

        if (zeroFree && possible(0, remaining)) {
            return num;
        }

        /*
            We need the smallest number >= num.

            Try changing one digit at position i to something
            greater than num[i]. Everything before i must remain
            exactly the same.

            We try positions from right to left because changing
            the rightmost possible position gives the smallest number.
        */

        array<long long, 4> prefixReq = req;

        // prefixReq represents requirements remaining after
        // processing positions [0 .. i-1].
        for (int i = 0; i < n; i++) {
            int current = num[i] - '0';

            // If the prefix itself contains zero, we cannot continue
            // keeping the prefix equal to num.
            if (current == 0)
                break;

            auto fCurrent = factors(current);

            for (int p = 0; p < 4; p++) {
                prefixReq[p] =
                    max(0LL, prefixReq[p] - (long long)fCurrent[p]);
            }

            // Try to make position i larger.
            for (int d = current + 1; d <= 9; d++) {
                auto fd = factors(d);

                array<long long, 4> nxt = prefixReq;

                for (int p = 0; p < 4; p++) {
                    nxt[p] =
                        max(0LL, nxt[p] - (long long)fd[p]);
                }

                int suffixLen = n - i - 1;

                if (possible(suffixLen, nxt)) {
                    string suffix = buildSuffix(suffixLen, nxt);

                    if (!suffix.empty() || suffixLen == 0) {
                        return num.substr(0, i) +
                               char('0' + d) +
                               suffix;
                    }
                }
            }
        }

        /*
            No number of the same length works.

            Therefore, use n+1 digits.
            The smallest zero-free n+1 digit number satisfying
            the condition is the lexicographically smallest
            valid string of length n+1.
        */
        if (!possible(n + 1, req))
            return "-1";

        return buildSuffix(n + 1, req);
    }
};