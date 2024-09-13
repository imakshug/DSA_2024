// 1310. XOR Queries of a Subarray

class Solution {
public:
    // Function to calculate XOR from index a to b
    int calculateXor(int a, int b, vector<int>& arr) {
        int result = 0;
        for (int i = a; i <= b; ++i) {
            result ^= arr[i];
        }
        return result;
    }

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        // Step 1: Loop through each query in the queries array
        for (int i = 0; i < queries.size(); ++i) {
            int a = queries[i][0];  // starting index
            int b = queries[i][1];  // ending index

            // Step 2: Call the calculateXor function for the range a to b
            int xorResult = calculateXor(a, b, arr);

            // Step 3: Store the result in the ans vector
            ans.push_back(xorResult);
        }

        // Step 4: Return the result after all queries
        return ans;
    }
};
