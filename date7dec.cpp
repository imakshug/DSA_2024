//1760. Minimum Limit of Balls in a Bag
class Solution {
public:
    int minimumSize(vector<int>& nums, int mop) {
        int l = 1 , r = *max_element(nums.begin(),nums.end()),ans =-1;
        while(l<=r){
            int mid = (l+r)/2 , curr=0;
            for(int i:nums){
                /* 
                see if you want to divide i into size of mid at max you can use division
                   suppose 8/3 = 2 , means we get 3 3 ( 2 full 3s ) and 2 (remaining)
                   since the remaining is always < maxi it is fine to +, expect when i%mid =0
                   why ? becuase suppose 8/3 = 2 that means we performed 2 operations to make
                   it <= mid 8 --> 2 6 --> 2 3 3 ( 2 operations)
                   but 9/3 = 3 but we can split 9 into 3 with just use 2
                   operations 9 --> 3 6 --> 3 3 hence when i%mid=0 perform  -1;
                */
                curr += i/mid;
                if(i%mid==0) curr--;
                /* 
                    now instead of writing these two lines you can just
                    use (i-1)/mid why ? becuase iy brings down the 9%3 to 8%3 = 0 
                    effectively removing 1 from the cases when % is 0 and other cases 
                    not % =0 remain same ex : 7%3 =  2 and 6%2 still 2
                */
            }
            if(curr<=mop){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
