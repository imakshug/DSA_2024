// patching Array

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long curr = 1;
        int total = 0;
        int res = 0;
        int i = 0;
        
        while (curr <= n) {
            if (i < nums.size() && nums[i] <= curr) {
                total += nums[i];
                curr = total + 1;
                ++i;
            } else {
                ++res;
                total += curr;
                curr = total + 1;
            }
        }
        
        return res;
    }
};

