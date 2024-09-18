// largest number

class Solution {
public:
    string largestNumber(vector<int> &nums){
        sort(nums.begin(), nums.end(),[](int left, int right){
            string l=to_string(left);
            string r=to_string(right);
            return l+r>r+l;
        });
        if(nums[0]==0) return "0";
        string largest="";
        for(auto x: nums) largest+=to_string(x);
        return largest;
    }
};
