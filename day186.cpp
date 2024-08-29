// 947. Most Stones Removed with Same Row or Column

class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<bool> &visited){
        
        visited[i] = true;
        for(auto index : adj[i]){
            if(!visited[index]){
                dfs(index, adj, visited);
            }
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int total_stones = stones.size();
        vector<vector<int>>adj(total_stones);
        int i_max = total_stones - 1;
        for(int i = 0; i < i_max; i++){
            for(int j = i + 1; j < total_stones; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>visited(total_stones, false);
        int count = 0;
        for(int i = 0; i < total_stones; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }
        int ans = total_stones - count;
        return ans;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<bool> &visited){
        
        visited[i] = true;
        for(auto index : adj[i]){
            if(!visited[index]){
                dfs(index, adj, visited);
            }
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int total_stones = stones.size();
        vector<vector<int>>adj(total_stones);
        int i_max = total_stones - 1;
        for(int i = 0; i < i_max; i++){
            for(int j = i + 1; j < total_stones; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>visited(total_stones, false);
        int count = 0;
        for(int i = 0; i < total_stones; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }
        int ans = total_stones - count;
        return ans;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
