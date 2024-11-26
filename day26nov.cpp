// find champion

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            int v = edge[1];
            indegree[v]++;
        }
        
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (res != -1) return -1;
                res = i;
            }
        }

        return res;
    }
};
