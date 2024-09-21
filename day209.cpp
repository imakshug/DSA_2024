//386. Lexicographical Numbers

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(to_string(i));
        }
        sort(ans.begin(), ans.end());
         vector<int> result;
        for (const string& str : ans) {
            result.push_back(stoi(str));  // Convert string to integer
        }
        return result;
    }
};
