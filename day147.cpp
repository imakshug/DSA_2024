// build a matrix with conditions

class Solution {
    bool dfs(int node, vector<int>&vis,vector<int>&pathvis, stack<int> &st,
	         vector<vector<int>>&adj) {
		vis[node] = 1;
        pathvis[node]=1;
		for (auto it : adj[node]) {
			if (!vis[it]) {if(dfs(it, vis,pathvis, st, adj)==false) return false;}
            else if(pathvis[it]==1) return false;
		}
		st.push(node);
        pathvis[node]=0;
        return true;
	}
	bool topoSort(int V, vector<vector<int>>&adj,unordered_map<int,int>&locationMp)
	{
		vector<int>vis(V,0);
        vector<int>pathvis(V,0);
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if(dfs(i, vis,pathvis, st, adj)==false) return false;
			}
		}
        int location=0;
		while (!st.empty()) {
			if(st.top()!=0){
                locationMp[st.top()]=location++;
            }
			st.pop();
		}
        return true;
	}
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>adjx(k+1);
        vector<vector<int>>adjy(k+1);
        for(auto i:rowConditions){
            adjy[i[0]].push_back(i[1]);
        }
        for(auto i:colConditions){
            adjx[i[0]].push_back(i[1]);
        }
        unordered_map<int,int>xlocation; // element->col_no.
        unordered_map<int,int>ylocation; // element->row_no.
        bool rpossible=topoSort(k+1,adjy,ylocation);
        bool cpossible=topoSort(k+1,adjx,xlocation);
        if(!rpossible || !cpossible) return vector<vector<int>>{};
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            ans[ylocation[i]][xlocation[i]]=i;
        }
        return ans;
    }
};
