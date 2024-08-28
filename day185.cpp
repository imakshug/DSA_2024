//Count Sub Islands

class Solution {
public:

    bool solve(int i,int j,int n,int m,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
       if(i<0 || i>=n || j<0 || j>=m || grid2[i][j]==0){
          return true;
       }

       if(grid2[i][j]==1 && grid1[i][j]==0){
          return false;
       }
       grid1[i][j]=0;
       grid2[i][j]=0;

       bool left=solve(i,j+1,n,m,grid1,grid2);
       bool down=solve(i+1,j,n,m,grid1,grid2);
       bool up=solve(i-1,j,n,m,grid1,grid2);
       bool right=solve(i,j-1,n,m,grid1,grid2);

      return (left && right && up && down);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && grid1[i][j]==1){
                    if(solve(i,j,n,m,grid1,grid2)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
