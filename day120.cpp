// Minimum Number of K Consecutive Bit flips

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int l=0;
        int cnt=0;
        vector<int>dec(n,0);
        int ans=0;
        while(l<n){
           
            if(l+k<=n && nums[l]==0){
                cnt++;   
                ans++; 
                dec[l+k-1]=-1;
                nums[l]=!nums[l];        
            }
            cnt=cnt+dec[l];
            if(cnt%2!=0 && l+1<n){
                nums[l+1]=!nums[l+1];
            }
            l++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                return -1;
            }
        }
        return ans;
    }
};
