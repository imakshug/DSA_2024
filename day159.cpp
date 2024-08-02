// minimum swap to all group 1's together

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=0,n=nums.size();
        for(auto x:nums) if(x==1) k++;
        int cnt=0,mn=k;
        int s=0,e=0;
        for(s=0;s<n;s++){
            while(e<s+k){
                if(nums[e%n]==1) cnt++;
                e++;
            }
            mn=min(mn,k-cnt);
            if(nums[s]==1) cnt--;
        }
        return mn;
    }
};
