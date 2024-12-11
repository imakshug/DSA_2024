//2779. Maximum Beauty of an Array After Applying Operation

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort (nums.begin(),nums.end());
        int i=0;
        int j=0;
        int count=0;
        while(j<nums.size()){
            if ((nums[i]+k) >=(nums[j]-k)){
                count=max(count,j-i+1);
                j++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};
