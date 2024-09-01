// convert 1D Array into 2D Array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n!=original.size()) return {};
        vector<vector<int>> vec(m,vector<int>(n));
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vec[i][j]=original[k];
                k++;
            }
        }
        return vec;
    }
};
