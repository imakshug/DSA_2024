// sum of square numbers

#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long cc = static_cast<long long>(c); // Correctly cast c to long long
        long long s = 0;
        long long e = static_cast<long long>(sqrt(cc)); // Use cc to compute the square root

        while (s <= e) {
            long long a = s * s;
            long long b = e * e;

            if (a + b == cc)
                return true;
            else if (a + b > cc)
                e--;
            else
                s++;
        }

        return false;
    }
};

