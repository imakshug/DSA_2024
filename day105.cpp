//  Subarray Sums Divisible by K

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int>m;
        int j=0;
        int sum=0,ans=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            if(sum%k==0)
             ans++;
            if(m.find((sum%k+k)%k)!=m.end())
            ans+=m[(sum%k+k)%k];
             m[(sum%k+k)%k]++;
            j++;
            
        }
        return ans;
        
    }
};