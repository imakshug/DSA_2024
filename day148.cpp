// sort the people

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, int>> v;
        for(size_t i = 0; i < names.size(); ++i) v.emplace_back(heights[i], i);
        sort(v.begin(), v.end(), greater<>{});
        vector<string> ans(v.size());
        for(size_t i = 0; i < v.size(); ++i){
            ans[i]=move(names[v[i].second]);
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
