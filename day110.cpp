//Minimum Increment to Make Array Unique



#include <vector>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        // Sort the input vector
        std::sort(nums.begin(), nums.end());
        
        int ans = 0;
        int lastNum = nums[0];
        
        // Iterate through the sorted vector starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= lastNum) {
                // If current number is less than or equal to lastNum, we need to increment it
                ans += lastNum + 1 - nums[i];
                lastNum++;
            } else {
                // Otherwise, update lastNum to the current number
                lastNum = nums[i];
            }
        }
        
        return ans;
    }
};

