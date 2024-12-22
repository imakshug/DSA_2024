//2940. Find Building Where Alice and Bob Can Meet
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<pair<int,pair<int ,int>>>order;
        vector<int>ans(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
         int &a=queries[i][0],&b=queries[i][1];
         if(a>b) swap(a,b);
         if(a==b || heights[b]>heights[a]) ans[i]=b;
         else order.push_back({b,{heights[a],i}});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        sort(order.begin(),order.end());
        int j=0;
        for(int i=0;i<heights.size();i++){
         while( j<order.size() && i==order[j].first) q.push(order[j++].second);
         while(!q.empty() && q.top().first<heights[i]){
         ans[q.top().second]=i;
          q.pop();
         }
        }
        return ans;
    }
};
