// Target Sum

class Solution {
public:
    int solve(vector<int>& nums, int i, int sum, int& t){
        if(i==nums.size()){
            if(sum == t) return 1;
            else return 0;
        }

        int plus = solve(nums,i+1,sum+nums[i],t);
        int minus = solve(nums,i+1, sum-nums[i],t);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        return solve(nums,0,sum,target);
    }
};
