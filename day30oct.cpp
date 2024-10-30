//1671. Minimum Number of Removals to Make Mountain Array

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Calculate LIS lengths using binary search with direct updates
        vector<int> lis(n, 1), lisSeq;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(lisSeq.begin(), lisSeq.end(), nums[i]);
            if (it == lisSeq.end()) lisSeq.push_back(nums[i]);
            else *it = nums[i];
            lis[i] = lisSeq.size();
        }

        // Step 2: Calculate LDS lengths using binary search in reverse direction with direct updates
        vector<int> lds(n, 1), ldsSeq;
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(ldsSeq.begin(), ldsSeq.end(), nums[i]);
            if (it == ldsSeq.end()) ldsSeq.push_back(nums[i]);
            else *it = nums[i];
            lds[i] = ldsSeq.size();
        }

        // Step 3: Calculate minimum removals for a valid mountain
        int minRemovals = n;
        for (int i = 1; i < n - 1; i++) {
            if (lis[i] > 1 && lds[i] > 1) {  // Valid mountain peak
                minRemovals = min(minRemovals, n - (lis[i] + lds[i] - 1));
            }
        }

        return minRemovals;
    }
};
