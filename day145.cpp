// lucky no. in matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int mn = matrix[i][0];
            int ind = 0;
            bool add = true;
            for(int j=0; j<m; j++){
                if(mn != min(mn, matrix[i][j])){
                    ind = j;
                }
                mn = min(mn, matrix[i][j]);
            }
            for(int k=0; k<n; k++){
                if(mn < matrix[k][ind]){
                    add = false;
                    break;
                }
            }
            if(add){
                ans.push_back(mn);
            }
        }
        return ans;
    }
};
