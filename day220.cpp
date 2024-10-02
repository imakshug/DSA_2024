// 1331. Rank Transform of an Array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mpp;

        for(auto &it : arr){
            mpp[it] = 0;
        }

        int rank = 1;

        for(auto &it : mpp){
            mpp[it.first] = rank++;
        }

        vector<int> ans;

        for(int i = 0; i < arr.size(); i++){
            ans.push_back(mpp[arr[i]]);
        }

        return ans;
        
    }
};
