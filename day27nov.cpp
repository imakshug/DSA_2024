//3243. Shortest Distance After Road Addition Queries I

class Solution {
public:
int f(int point,int n,vector<vector<int>>&adj,vector<int>&dis)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({dis[point],point}); 
    while(!pq.empty())
    {
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(node==n-1)
        {
             
            break;
        }
        for(int i:adj[node])
        {
            if(dis[i]>d+1)
            {
                dis[i]=d+1;
                pq.push({d+1,i});
            }
        }
    }
    return dis[n-1];
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>dis(n);
        vector<int>ans;
        vector<vector<int>>adj(n);
        dis[0]=0;
        for(int i=0;i<n-1;i++)
        {
            adj[i].push_back(i+1);
            dis[i+1]=dis[i]+1;
        }
        for(auto it:queries)
        {
            adj[it[0]].push_back(it[1]);
            int res=f(it[0],n,adj,dis);
            ans.push_back(res);
        }
        return ans;
    }
};
