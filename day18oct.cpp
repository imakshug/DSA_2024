//2044. Count Number of Maximum Bitwise-OR Subsets

class Solution {
    
    public:
    
    int countMaxOrSubsets(vector<int>& nums) {
        
        int n = nums.size();

        // Step 1: Max subset or will be or of all elements
        int maxi = 0;
        for(int num : nums)
           maxi |= num;
        
        // Step 2: Using masters method inc count for all subsets with or maxi
        int count = 0;
        for(int i=0; i<(1 << n); i++){
            int curOr = 0;
            for(int j=0; j<n; j++){
                if(i & (1 << j))
                   curOr |= nums[j];
            }
            if(curOr == maxi)
               count++;
        }

        return count;

    }
};
