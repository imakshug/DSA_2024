class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        vector<int> firstDist(n+1, INT_MAX-1);
        vector<int> secondDist(n+1, INT_MAX);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<pair<int, int>> q;
        q.push({1, 0});
        firstDist[1] = 0;
        secondDist[1] = INT_MAX-1;

        while(!q.empty()) {
            int currNode = q.front().first;
            int currTime = q.front().second;
            q.pop();

            for(const auto &nextNode : graph[currNode]) {
                int waitTime = 0;
                if((currTime / change) % 2 == 1) waitTime += change -(currTime % change);
                int nextTime = currTime + waitTime + time;
                if(firstDist[nextNode] > nextTime) {
                    q.push({nextNode, nextTime});
                    secondDist[nextNode] = firstDist[nextNode];
                    firstDist[nextNode] = nextTime;
                } else if(nextTime > firstDist[nextNode] && secondDist[nextNode] > nextTime) {
                    q.push({nextNode, nextTime});
                    secondDist[nextNode] = nextTime;
                }
            }
        }

        return secondDist[n];
    }
};
