//2466. Count Ways To Build Good Strings

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        
        // Initialize dp array where dp[i] represents the number of good strings of length i
        vector<int> dp(high + 1, 0);
        
        // Base case: there's one way to make a string of length 0 (the empty string)
        dp[0] = 1;
        
        // Fill the dp array using the recurrence relation
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
        }
        
        // Sum the dp values from low to high to get the result
        int result = 0;
        for (int i = low; i <= high; ++i) {
            result = (result + dp[i]) % MOD;
        }
        
        return result;
    }
};
