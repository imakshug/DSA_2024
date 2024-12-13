//2593. Find Score of an Array After Marking All Elements

class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        vector<pair<int,int>> values;
        for(int i = 0; i < nums.size(); i++)
        {
            values.push_back({nums[i], i});
        }

        auto compare = [](const pair<int,int>&a, const pair<int,int>&b){
                            if(a.first != b.first)
                              return a.first < b.first;
                            return a.second < b.second;
        };

        sort(values.begin(), values.end(), compare);
        int n = nums.size();
        vector<bool> visited(n, false);

        long long score = 0;

        for(auto x : values)
        {
            if(visited[x.second] == false)
            {
                score += x.first;
                int leftIndex = x.second-1;
                if(leftIndex >= 0)
                {
                    visited[leftIndex] = true;
                }

                int rightIndex = x.second +1;
                if(rightIndex < n)
                {
                    visited[rightIndex] = true;
                }

                visited[x.second] = true;
            }
        }

        return score;

    }
};
