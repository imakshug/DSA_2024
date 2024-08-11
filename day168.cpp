// minimum number of days to disconnecct

class Solution {
    private:
    void noOfIslands(vector<vector<int>>& grid, int delx[], int dely[], int m , int n, queue<pair<int, int>> &q, vector<vector<int>> &vis) {
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
                for(int i = 0; i < 4; i++) {
                    int nrow = row + delx[i];
                    int ncol = col + dely[i];
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 &&  !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
        }
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<int> len;
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                    vis[i][j] = 1;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    noOfIslands(grid, delx, dely, m, n, q, vis);
                }
            }
        }
        if(count > 1 || count == 0) return 0;
        int maxi = INT_MIN;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                grid[i][j] = 0;
                int count = 0;
                vector<vector<int>> vis(m, vector<int>(n, 0));
                for(int k = 0; k < m; k++) {
                    for(int l = 0; l < n; l++) {
                         if(grid[k][l] == 1 && !vis[k][l]) {
                              count++;
                              vis[k][l] = 1;
                              queue<pair<int, int>> q;
                              q.push({k, l});
                              noOfIslands(grid, delx, dely, m, n, q, vis);
                         }
                    }
                }
                maxi = max(maxi, count);
                grid[i][j] = 1;
                }
            }
        }
        return (maxi >= 2 || maxi == 0) ? 1 : 2;
    }
};
