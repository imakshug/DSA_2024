// regions cut by slashes

class Solution {
public:
    void dfs(int m, int n, int i, int j, vector<vector<int>>& mat) {
        if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == 1)
            return;
        mat[i][j] = 1;
        dfs(m, n, i + 1, j, mat);
        dfs(m, n, i - 1, j, mat);
        dfs(m, n, i, j + 1, mat);
        dfs(m, n, i, j - 1, mat);
        return;
    }
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> mat(rows * 3, vector<int>(cols * 3, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '/') {
                    mat[i * 3][j * 3 + 2] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    mat[i * 3][j * 3] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        for (auto it : mat) {
            for (auto val : it)
                cout << val << " ";
            cout << endl;
        }

        int regions = 0;
        for (int i = 0; i < rows * 3; i++) {
            for (int j = 0; j < cols * 3; j++) {
                if (mat[i][j] == 0) {
                    dfs(rows * 3, cols * 3, i, j, mat);
                    regions += 1;
                }
            }
        }
        return regions;
    }
};
