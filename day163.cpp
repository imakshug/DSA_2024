//3016. Minimum Number of Pushes to Type Word II

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26, 0);
        for(auto s:word){
            v[s-'a']++;
        }
        sort(v.begin(), v.end(), greater<int>());
        int ans=0;
        for(int i=0; i<26; i++){
            ans += v[i]*((i/8)+1);
        }
        return ans;
    }
};
