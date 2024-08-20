// stone game 2


class Solution {
public:
    int n;
    int dp[2][101][101];

    int solveForAlice(int person,int idx,int M,vector<int>& piles)
    {
        // base case
        if(idx>=n)
        return 0;

        // overlapping subproblems
        if(dp[person][idx][M]!=-1)
        return dp[person][idx][M];

        // if person is 1(ALice) then take result as -1 otherwise for
        // bob take result as INT_MAX
        int result=(person==1)?-1:INT_MAX;
        int stones=0;

        for(int x=1;x<=min(2*M,n-idx);x++)
        {
            stones+=piles[idx+x-1];

            // if its Alice turn
            if(person==1)
            {
                result=max(result,stones+solveForAlice(0,idx+x,max(M,x),piles));
            }
            // if its Bob turn
            else
            {
                // this time we will not add stones
                result=min(result,solveForAlice(1,idx+x,max(M,x),piles));
            }
        }

        return dp[person][idx][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        
        return solveForAlice(1,0,1,piles);
    }
};
