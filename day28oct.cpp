//2501. Longest Square Streak in an Array

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        map<int,int>mp;
        for(auto num:nums){
            int root=sqrt(num);
            if (root*root==num&&mp[root]>0){
                mp[num]=mp[root]+1;
            } else {
                mp[num]=1;
            }
            maxi=max(maxi,mp[num]);
        }
        return maxi>1?maxi:-1;
    }
};
