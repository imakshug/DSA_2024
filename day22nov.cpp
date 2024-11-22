//

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
         unordered_map<string,int>mp;
         for(auto& row : matrix)
         {
            int first = row[0];
            string cur;
            for(int ele: row)
            {
                if(ele==first)  cur.push_back('0');
                else            cur.push_back('1');
            }
            mp[cur]++;
         }
            int maxi=0;
            for(auto& [string,freq] : mp)
                maxi=max(maxi,freq);
            
            return maxi;
    }
};
