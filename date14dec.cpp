// Continuous Subarrays

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        int l =0;
        int r = 0;
        long long int wins = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(r=0;r<nums.size();++r){
            maxi = max(maxi,nums[r]);
            mini = min(mini,nums[r]);
            if(maxi-mini>2){
                wins = r-l;
                ans+=wins*(wins+1)/2;
                l = r;
                maxi = mini = nums[r];
                while(abs(nums[r] - nums[l-1])<=2){
                    l--;
                    maxi = max(maxi,nums[l]);
                    mini = min(mini,nums[l]);
                }
                if(l<r){
                    wins = r-l;
                    ans-=wins*(wins+1)/2;
                }
            }
        }
        wins = r-l;
        ans+=wins*(wins+1)/2;
        return ans;

    }
};
