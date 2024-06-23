// Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

class Solution {
public:
 int longestSubarray(vector<int>& nums, int limit) {

    int n = nums.size();

    // To get the max and min element in O(1). 
    // this will help us to check for a given inserted element,
    // did all the possible pairs inside it satisfy the condition
    //  | x - y | <= limit
    multiset<int> st;

    // I am taking multiset to handle Duplicates in the subarray.. 
    // Map can also be used

    int i = 0, j = 0, mx = 0;

    while(j < n){

        st.insert(nums[j]);

        // checking for valid Subarray
        while(i <= j && (*st.rbegin() - *st.begin()) > limit){

            // removing the ith element of the 
            st.erase(st.find(nums[i]));
            i++;

            }

            // Keeping track of the max valid subarray , 
            // st.size() can be used in place of j - i + 1
            mx = max(mx, j - i + 1);    

            j++;         

        }

    return mx;
        
    }
};
