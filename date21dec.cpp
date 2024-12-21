// 2872. Maximum Number of K-Divisible Components
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int maxComponents = 0;
        function<long long(int, int)> dfs = [&](int node, int parent) {
            long long sum = values[node]; 
            
            for (int neighbor : adj[node]) {
                if (neighbor == parent) continue; 
                long long subTreeSum = dfs(neighbor, node);
                if (subTreeSum % k == 0) {
                    maxComponents++; 
                } else {
                    sum += subTreeSum;
                }
            }
            return sum;
        };

        dfs(0, -1);
        if (accumulate(values.begin(), values.end(), 0LL) % k == 0) {
            maxComponents++;
        }

        return maxComponents;
    }
};
