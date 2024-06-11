// Relative sort

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Step 1: Count occurrences of each number in arr1 using an unordered_map
        unordered_map<int, int> mpp;
        for(int i : arr1){
            mpp[i]++;
        }

        vector<int> ans;

        // Step 2: Add elements of arr2 to ans in the order they appear in arr2
        for(int x : arr2){
            while(mpp[x] > 0){
                ans.push_back(x);
                mpp[x]--;
            }
        }

        // Step 3: Collect remaining elements from arr1 that were not in arr2
        vector<int> remaining;
        for(auto it : mpp){
            while(it.second > 0){
                remaining.push_back(it.first);
                it.second--;
            }
        }

        // Step 4: Sort the remaining elements in ascending order
        sort(remaining.begin(), remaining.end());

        // Step 5: Add sorted remaining elements to ans
        for(int x : remaining){
            ans.push_back(x);
        }

        return ans;
    }
};
