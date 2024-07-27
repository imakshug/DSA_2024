//1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    void addEdge(int u, int v, int wt) {
        mp[u].push_back({v, wt});
        mp[v].push_back({u, wt});
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            addEdge(u, v, wt);
        }
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto a : mp) {
            for (auto b : a.second) {
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int src = 0; src < n; src++) {
                for (int dest = 0; dest < n; dest++) {
                    dist[src][dest] =
                        min(dist[src][dest], dist[src][i] + dist[i][dest]);
                }
            }
        }
        int minNeighborCount = n;
        int cityWithMinNeighbors = -1;
        for (int i = 0; i < n; i++) {
            int neighborCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    neighborCount++;
                }
            }
            if (neighborCount <= minNeighborCount) {
                minNeighborCount = neighborCount;
                cityWithMinNeighbors = i;
            }
        }
        return cityWithMinNeighbors;
    }
};
