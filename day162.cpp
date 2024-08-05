// kth distinct string in an array

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> ump;
        for(auto s: arr) {
            ump[s]++;
        }
        for(auto s: arr) {
            if(ump[s] == 1) {
                k--;
                if(k == 0) return s;
            }
        }
        return "";
    }
};
