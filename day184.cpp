//1514. Path with Maximum Probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<double> prob(n, 0);
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        queue<int> q;
        q.push(start_node);
        prob[start_node] = 1;
        int y;
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            for (int i = 0; i < adj[s].size(); i++) {
                double temp = adj[s][i].second * prob[s];
                y = adj[s][i].first;
                if (prob[y] < temp) {
                    prob[y] = temp;
                    q.push(y);
                }
            }
        }
        return prob[end_node];
    }
};
