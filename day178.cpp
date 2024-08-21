// starnge printer

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        // dp[i][j] will store the minimum turns needed to print the substring s[i:j+1]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: each single character needs 1 turn to be printed
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Fill the dp table for substrings of increasing length
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                
                // Start by assuming that we print each character separately
                dp[i][j] = dp[i][j-1] + 1;
                
                // Check if there is any way to merge characters to reduce the number of prints
                for (int k = i; k < j; ++k) {
                    if (s[k] == s[j]) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j-1]);
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};
