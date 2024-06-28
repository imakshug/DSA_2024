//Maximum Total Importance of Roads

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> cities(n);
        for (auto& road : roads) {
            cities[road[0]].first++;
            cities[road[1]].first++;
        }
        sort(cities.begin(), cities.end());
        int num = 1;
        for (auto& city : cities) {
            city.second = num++;
        }
        long long ans = 0;
        for (auto& city : cities) {
            ans += (long long)city.first * city.second;
        }
        return ans;
    }
};
