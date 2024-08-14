// Find K-th Smallest Pair Distance

#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n-1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            int j = 0;

            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= mid) {
                    ++j;
                }
                count += j - i - 1;
            }

            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
