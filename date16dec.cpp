// 3264. Final Array State After K Multiplication Operations I
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        for (int i=0;i<nums.size();i++) q.push({nums[i],i});
        while (k>0){
            k--;
            q.push({q.top().first*multiplier,q.top().second});
            q.pop();
        }
        int a[10000];
        vector<int> b;
        while (q.size()) a[q.top().second]=q.top().first,q.pop();
        for (int i=0;i<nums.size();i++) b.push_back(a[i]);
        return b;
    }
};
