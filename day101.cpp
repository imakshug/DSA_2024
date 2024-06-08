// Continuous Subarray Sum

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the input array
        unordered_map<int, int> remainder_map; // Create a map to store the first occurrence of remainders
        remainder_map[0] = -1; // Initialize with a dummy value to handle cases where the subarray starts from index 0
        int sum = 0; // Initialize the cumulative sum

        for (int i = 0; i < n; ++i) {
            sum += nums[i]; // Update the cumulative sum
            int remainder = sum % k; // Compute the remainder of the cumulative sum with k

            if (remainder_map.find(remainder) != remainder_map.end()) {
                // If the remainder has been seen before, check the length of the subarray
                if (i - remainder_map[remainder] > 1) {
                    return true; // Found a valid subarray
                }
            } else {
                // Store the first occurrence of this remainder
                remainder_map[remainder] = i;
            }
        }

        return false; // No valid subarray found
    }
};
