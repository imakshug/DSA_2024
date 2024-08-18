// ugly number

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        int pointer1=0;
        int pointer2=0;
        int pointer3=0;
        for(int i=1;i<n;i++){
            int twomul = dp[pointer1] * 2;
            int threemul = dp[pointer2] * 3;
            int fivemul = dp[pointer3] * 5;

            dp[i]=min(twomul,min(threemul,fivemul));
            if(dp[i] == twomul) pointer1++;
            if(dp[i] == threemul) pointer2++;
            if(dp[i] == fivemul) pointer3++;
            
        }
        return dp[n-1];
    }
};
