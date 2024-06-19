//  Minimum Number of Days to Make m Bouquets

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int count(vector<int>& b, int l, int k) {
        int n = b.size();
        int count = 0, maxi = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] <= l) {
                count++;
            } else {
                maxi += (count / k);
                count = 0;
            }
        }
        maxi += (count / k);
        return maxi;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) {
            return -1;
        }
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = h;
        while (l <= h) {
            int mindays = (l + h) / 2;
            int p = count(bloomDay, mindays, k);
            if (p >= m) {
                ans = mindays;
                h = mindays - 1;
            } else {
                l = mindays + 1;
            }
        }
        return ans;
    }
};


