// 1508. Range Sum of Sorted Subarray Sums

class Solution {
public:
const int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int res = 0;
        if(n == 1) return nums[0];

        vector<int> v;

        for(int i=0;i<n-1;i++){
            int sum = nums[i];
            v.push_back(sum);
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        v.push_back(nums[n-1]);
        sort(v.begin(),v.end());

        for(int i = left-1;i<=right-1;i++){
            res = (res + v[i]%MOD)%MOD;
        }
        return res;
    }
};
