//1593. Split a String Into the Max Number of Unique Substrings

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return maximum_unique_split(s, 0, seen);
    }
    int maximum_unique_split(string s , int start, unordered_set<string> &seen ){
        if(start == s.size()) return 0;
        int maxsplit = 0;
        string current = "";

        for(int i = start; i < s.size(); i++){
            current += s[i];
            if(seen.find(current) == seen.end()){
                seen.insert(current);
                maxsplit = max(maxsplit, 1 + maximum_unique_split(s, i+1, seen));
                seen.erase(current);
            }
        }
        return maxsplit;
    }
};
