//2419. Longest Subarray With Maximum Bitwise AND

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 1;

        int maxi = 0;
        for (int& num : nums) {
            maxi = max(maxi, num);
        }

        int curr = 0;
        for (int& num : nums) {
            if (num == maxi) {
                curr++;
                ans = max(curr, ans);
            } else {
                curr = 0;
            }
        }

        return ans;
    }
};
