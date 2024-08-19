// two keys keyboard 

class Solution {
public:
    int solve(int count,int paste,int n,vector<vector<int>>& dp){
        if(count==n) return 0;
        if(count>n) return 1000;
        if(dp[count][paste]!=-1) return dp[count][paste];
        int a=1+solve(count+paste,paste,n,dp);
        int b=2+solve(count*2,count,n,dp);
        return dp[count][paste]=min(a,b);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return 1+solve(1,1,n,dp);
    }
};
