//1590. Make Sum Divisible by P
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int sum=0;
        int n=nums.size();
        vector<long long int> s(n,0);
        map<int,int> rem;
        sum=nums[0];
        s[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            s[i]=nums[i]+s[i-1];
        }
        if(sum%p==0)
        {
            return 0;
        }
        int d;
        int ans=INT_MAX;
        d=sum%p;
        for(int i=0;i<nums.size();i++)
        {
            int pt=(s[i]%p-d+p)%p;
            if((s[i]%p+p-d)%p==0 && i<nums.size()-1)
            {
                ans=min(ans,i+1);
            }
            if(rem.find(pt)!=rem.end())
            {
                ans=min(ans,i-rem[(s[i]%p+p-d)%p]);
            }
            rem[s[i]%p]=i;
        }
        return (ans!=INT_MAX)?ans:-1;
    }
};
