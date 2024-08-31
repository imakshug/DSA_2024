// path with maximum probability 

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
…
